#include "global.h"
#include "malloc.h"
#include "data.h"
#include "decompress.h"
#include "pokemon.h"
#include "pokemon_sprite_visualizer.h"
#include "text.h"
#include "menu.h"

void LZDecompressWram(const u32 *src, void *dest)
{
    LZ77UnCompWram(src, dest);
}

void LZDecompressVram(const u32 *src, void *dest)
{
    LZ77UnCompVram(src, dest);
}

// Checks if `ptr` is likely LZ77 data
// Checks word-alignment, min/max size, and header byte
// Returns uncompressed size if true, 0 otherwise
u32 IsLZ77Data(const void *ptr, u32 minSize, u32 maxSize)
{
    const u8 *data = ptr;
    u32 size;
    // Compressed data must be word aligned
    if (((u32)ptr) & 3)
        return 0;
    // Check LZ77 header byte
    // See https://problemkaputt.de/gbatek.htm#biosdecompressionfunctions
    if (data[0] != 0x10)
        return 0;

    // Read 24-bit uncompressed size
    size = data[1] | (data[2] << 8) | (data[3] << 16);
    if (size >= minSize && size <= maxSize)
        return size;
    return 0;
}

static inline u32 DoLoadCompressedSpriteSheet(const struct CompressedSpriteSheet *src, void *buffer)
{
    struct SpriteSheet dest;

    dest.data = buffer;
    dest.size = src->size;
    dest.tag = src->tag;
    return LoadSpriteSheet(&dest);
}

u32 LoadCompressedSpriteSheet(const struct CompressedSpriteSheet *src)
{
    void *buffer = malloc_and_decompress(src->data, NULL);
    u32 ret = DoLoadCompressedSpriteSheet(src, buffer);
    Free(buffer);

    return ret;
}

u32 LoadCompressedSpriteSheetOverrideBuffer(const struct CompressedSpriteSheet *src, void *buffer)
{
    LZDecompressWram(src->data, buffer);
    return DoLoadCompressedSpriteSheet(src, buffer);
}

// This can be used for either compressed or uncompressed sprite sheets
u32 LoadCompressedSpriteSheetByTemplate(const struct SpriteTemplate *template, s32 offset)
{
    struct SpriteTemplate myTemplate;
    struct SpriteFrameImage myImage;
    u32 size;

    // Check for LZ77 header and read uncompressed size, or fallback if not compressed (zero size)
    if (IsCompressedData(template->images->data))
    {
        size = GetDecompressedDataSize(template->images->data);
        void *buffer = malloc_and_decompress(template->images->data, NULL);
        myImage.data = buffer;
        myImage.size = size + offset;
        myTemplate.images = &myImage;
        myTemplate.tileTag = template->tileTag;

        u32 ret = LoadSpriteSheetByTemplate(&myTemplate, 0, offset);
        Free(buffer);
        return ret;
    }
    return LoadSpriteSheetByTemplate(template, 0, offset);

}

u32 LoadCompressedSpritePalette(const struct CompressedSpritePalette *src)
{
    return LoadCompressedSpritePaletteWithTag(src->data, src->tag);
}

u32 LoadCompressedSpritePaletteWithTag(const u32 *pal, u16 tag)
{
    u32 index;
    struct SpritePalette dest;
    void *buffer = malloc_and_decompress(pal, NULL);

    dest.data = buffer;
    dest.tag = tag;
    index = LoadSpritePalette(&dest);
    Free(buffer);
    return index;
}

void LoadCompressedSpritePaletteOverrideBuffer(const struct CompressedSpritePalette *src, void *buffer)
{
    struct SpritePalette dest;

    LZ77UnCompWram(src->data, buffer);
    dest.data = buffer;
    dest.tag = src->tag;
    LoadSpritePalette(&dest);
}

u32 LoadCompressedSpritePalette(const struct CompressedSpritePalette *src)
{
    return LoadCompressedSpritePaletteWithTag(src->data, src->tag);
}

u32 LoadCompressedSpritePaletteWithTag(const u32 *pal, u16 tag)
{
    u32 index;
    struct SpritePalette dest;
    void *buffer = malloc_and_decompress(pal, NULL);

    dest.data = buffer;
    dest.tag = tag;
    index = LoadSpritePalette(&dest);
    Free(buffer);
    return index;
}

void LoadCompressedSpritePaletteOverrideBuffer(const struct CompressedSpritePalette *src, void *buffer)
{
    struct SpritePalette dest;

    LZ77UnCompWram(src->data, buffer);
    dest.data = buffer;
    dest.tag = src->tag;
    LoadSpritePalette(&dest);
}

void DecompressPicFromTable(const struct CompressedSpriteSheet *src, void *buffer)
{
    DecompressDataWithHeaderWram(src->data, buffer);
}

void HandleLoadSpecialPokePic(bool32 isFrontPic, void *dest, s32 species, u32 personality)
{
    LoadSpecialPokePic(dest, species, personality, isFrontPic);
}

<<<<<<< HEAD
//  Wrapper function for all decompression calls using formats with headers
//  calls the correct decompression function depending on the header
//  VRAM version
void DecompressDataWithHeaderVram(const u32 *src, void *dest)
{
    union CompressionHeader header;
    CpuCopy32(src, &header, 8);
    switch (header.smol.mode)
    {
        case MODE_LZ77:
            LZ77UnCompVram(src, dest);
            break;
        case IS_TILEMAP:
            SmolDecompressTilemap(&header.smolTilemap, &src[2], dest);
            break;
        case BASE_ONLY:
        case ENCODE_SYMS:
        case ENCODE_DELTA_SYMS:
        case ENCODE_LO:
        case ENCODE_BOTH:
        case ENCODE_BOTH_DELTA_SYMS:
            SmolDecompressData(&header.smol, &src[2], dest);
            break;
        default:
            DecompressionError(src, HEADER_ERROR);
    }
}

//  Wrapper function for all decompression calls using formats with headers
//  calls the correct decompression function depending on the header
//  WRAM version
void DecompressDataWithHeaderWram(const u32 *src, void *dest)
{
    union CompressionHeader header;
    CpuCopy32(src, &header, 8);
    switch (header.smol.mode)
    {
        case MODE_LZ77:
            FastLZ77UnCompWram(src, dest);
            break;
        case IS_TILEMAP:
            SmolDecompressTilemap(&header.smolTilemap, &src[2], dest);
            break;
        case BASE_ONLY:
        case ENCODE_SYMS:
        case ENCODE_DELTA_SYMS:
        case ENCODE_LO:
        case ENCODE_BOTH:
        case ENCODE_BOTH_DELTA_SYMS:
            SmolDecompressData(&header.smol, &src[2], dest);
            break;
        default:
            DecompressionError(src, HEADER_ERROR);
    }
}

#define REP0(X)
#define REP1(X) X
#define REP2(X) REP1(X) X
#define REP3(X) REP2(X) X
#define REP4(X) REP3(X) X
#define REP5(X) REP4(X) X
#define REP6(X) REP5(X) X
#define REP7(X) REP6(X) X
#define REP8(X) REP7(X) X
#define REP9(X) REP8(X) X
#define REP10(X) REP9(X) X

#define REP(TENS,ONES,X) \
  REP##TENS(REP10(X)) \
  REP##ONES(X)

//  Unpack packed tANS encoded data symbol frequences into their individual parts
static __attribute__((always_inline)) inline void UnpackFrequenciesLoop(const u32 *packedFreqs, u16 *freqs, u32 i)
{
    // Loop unpack
    freqs[i*5 + 0] = (packedFreqs[i] >> (6*0)) & PACKED_FREQ_MASK;
    freqs[i*5 + 1] = (packedFreqs[i] >> (6*1)) & PACKED_FREQ_MASK;
    freqs[i*5 + 2] = (packedFreqs[i] >> (6*2)) & PACKED_FREQ_MASK;
    freqs[i*5 + 3] = (packedFreqs[i] >> (6*3)) & PACKED_FREQ_MASK;
    freqs[i*5 + 4] = (packedFreqs[i] >> (6*4)) & PACKED_FREQ_MASK;

    freqs[15] += (packedFreqs[i] & PARTIAL_FREQ_MASK) >> (30 - 2*i);
}

static __attribute__((always_inline)) inline void UnpackFrequencies(const u32 *packedFreqs, u16 *freqs)
{
    freqs[15] = 0;

    UnpackFrequenciesLoop(packedFreqs, freqs, 0);
    UnpackFrequenciesLoop(packedFreqs, freqs, 1);
    UnpackFrequenciesLoop(packedFreqs, freqs, 2);
}

// This is a small function, so we can store it in IWRAM for improved performance and don't need to worry about it taking too much precious IWRAM space.
ARM_FUNC __attribute__((section(".iwram.code"))) __attribute__((noinline)) static void CopyTable(u32 *dst, const u32 *src, u32 size, u32 orrVal)
{
    for (u32 i = 0; i < size; i++) {
        *dst++ = (*src++) | orrVal;
    }
}

//  Build the tANS decompression table from the specified frequencies and the precomputed helper struct
__attribute__((optimize("-O3"))) static void BuildDecompressionTable(const u32 *packedFreqs, u32 *table)
{
    u16 freqs[16];

    UnpackFrequencies(packedFreqs, freqs);

    for (u8 i = 0; i < 16; i++)
    {
        const u32 *srcTemplate;

        switch (freqs[i]) {
        case 0:
            break;
        default: {
            srcTemplate = &sYkTemplate[freqs[i]];
            CopyTable(table, srcTemplate, freqs[i], i << 3);
            table += freqs[i];
            srcTemplate += freqs[i];
            break;
        }
        case 1:
            srcTemplate = &sYkTemplate[1];
            REP(0, 1, *table++ = *srcTemplate++ | (i << 3);)
            break;
        case 2:
            srcTemplate = &sYkTemplate[2];
            REP(0, 2, *table++ = (*srcTemplate++) | (i << 3);)
            break;
        case 3:
            srcTemplate = &sYkTemplate[3];
            REP(0, 3, *table++ = (*srcTemplate++) | (i << 3);)
            break;
        }
    }
}

static IWRAM_DATA u8 sBitIndex = 0;
static IWRAM_DATA const u32 *sDataPtr = 0;
static IWRAM_DATA u32 sCurrState = 0;

// 33 because of FastUnsafeCopy32, we divide by 4 because the buffer is an array of u32
#define FUNC_BUFFER_SIZE(funcStart, funcEnd)(((u32)(funcEnd) - (u32)(funcStart) + 33) / 4)

extern void FastUnsafeCopy32(void *, const void *, u32 size);

//  Dark Egg magic
static inline void CopyFuncToIwram(void *funcBuffer, const void *funcStartAddress, const void *funcEndAdress)
{
    FastUnsafeCopy32(funcBuffer, funcStartAddress, funcEndAdress - funcStartAddress);
}

// The reason for macros and unrolling the loops stems from the following:
// currK can be max 6, meaning in the worst case scenario it takes minimum 4 loop iterations, where we don't need to check if bitIndex is >= 32, because it's mathematically impossible for it to be.
// This optimization matters for large images, because we don't waste a cycle on comparing operations. If the loops run over 5000 times in total, these can be costly.

#define LOT_LOOP_MAIN(nibble)   \
{ \
    u32 ykVals = ykTable[sCurrState];   \
    symbol |= TABLE_READ_SYMBOL(ykVals) << (nibble*4);   \
    currK = TABLE_READ_K(ykVals);   \
    sCurrState = TABLE_READ_Y(ykVals);  \
    sCurrState += (currBits >> bitIndex) & TABLE_READ_MASK(ykVals); \
    bitIndex += currK;  \
}

// The same for all the loops
#define LOOP_BITADVANCE() \
{   \
    currBits = *data++; \
    bitIndex -= 32; \
    if (bitIndex != 0)  \
    {   \
        sCurrState += (currBits & ((1u << bitIndex) - 1)) << (currK - bitIndex); \
    } \
}
//  Inner loop of tANS decoding for Lengths and Offset data for decompression instructions, uses u8 data sizes
//  Basic process for decoding a tANS encoded value is to read the current symbol from the decoding table, then calculate the next state
//  from the y and k values for the current state and add the value read from the next k bits in the bitstream
ARM_FUNC __attribute__((flatten, noinline, no_reorder)) __attribute__((optimize("-O3"))) static void DecodeLOtANSLoop(const u32 *data, u32 *ykTable, u8 *resultVec, u8 *resultVecEnd)
{
    u32 currBits = *data++;
    u32 bitIndex = sBitIndex;
    u16 *resultVec_u16 = (u16 *) resultVec;

    do
    {
        u32 currK;
        u32 symbol = 0;

        {
            LOT_LOOP_MAIN(0);
            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                LOT_LOOP_MAIN(1);
                LOT_LOOP_MAIN(2);
                LOT_LOOP_MAIN(3);

                goto LOOP_STORE;
            }
        }
        {
            LOT_LOOP_MAIN(1);
            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                LOT_LOOP_MAIN(2);
                LOT_LOOP_MAIN(3);

                goto LOOP_STORE;
            }
        }
        {
            LOT_LOOP_MAIN(2);
            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                LOT_LOOP_MAIN(3);

                goto LOOP_STORE;
            }
        }
        {
            LOT_LOOP_MAIN(3);
            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                *resultVec_u16++ = symbol;
                if (resultVec_u16 >= (u16 *) resultVecEnd)
                    break;

                symbol = 0;

                LOT_LOOP_MAIN(0);
                LOT_LOOP_MAIN(1);
                LOT_LOOP_MAIN(2);
                LOT_LOOP_MAIN(3);
            }
        }

LOOP_STORE:
        *resultVec_u16++ = symbol;
    } while (resultVec_u16 < (u16 *) resultVecEnd);

    sBitIndex = bitIndex;
    sDataPtr = data - 1;
}

//  Dark Egg magic
ARM_FUNC __attribute__((no_reorder)) static void SwitchToArmCallLOtANS(const u32 *data, u32 *ykTable, void *resultVec, void *resultVecEnd, void (*decodeFunction)(const u32 *data, u32 *ykTable, void *resultVec, void *resultVecEnd))
{
    decodeFunction(data, ykTable, resultVec, resultVecEnd);
}

//  Function that decodes tANS encoded LO data, resulting data is u8 values
static void DecodeLOtANS(const u32 *data, const u32 *pFreqs, u8 *resultVec, u32 count)
{
    BuildDecompressionTable(pFreqs, sWorkingYkTable);

    // We want to store in packs of 2, so count needs to be divisible by 2
    u32 remainingCount = count % 2;

    u32 funcBuffer[FUNC_BUFFER_SIZE(DecodeLOtANSLoop, SwitchToArmCallLOtANS)];

    CopyFuncToIwram(funcBuffer, DecodeLOtANSLoop, SwitchToArmCallLOtANS);
    SwitchToArmCallLOtANS(data, sWorkingYkTable, resultVec, &resultVec[count - remainingCount], (void *) funcBuffer);

    if (remainingCount)
    {
        u32 currBits = *sDataPtr;
        u32 symbol = 0;
        for (u32 currNibble = 0; currNibble < 2; currNibble++)
        {
            u32 ykVals = sWorkingYkTable[sCurrState];
            symbol |= TABLE_READ_SYMBOL(ykVals) << (currNibble*4);
            u32 currK = TABLE_READ_K(ykVals);
            sCurrState = TABLE_READ_Y(ykVals);
            sCurrState += (currBits >> sBitIndex) & TABLE_READ_MASK(ykVals);
            sBitIndex += currK;
            if (sBitIndex >= 32)
            {
                currBits = *(++sDataPtr);
                sBitIndex -= 32;
                if (sBitIndex != 0)
                {
                    sCurrState += (currBits & ((1u << sBitIndex) - 1)) << (currK - sBitIndex);
                }
            }
        }
        resultVec[count - remainingCount] = symbol;
    }
}

// The reason this function is UNUSED, because it's currently exactly the same as `DecodeLOtANSLoop`(as it was optimized out for halfwords and not bytes as it's technically designed).
// If ever DecodeLOtANSLoop or DecodeSymtANSLoop were to change make sure to uncomment the 'CopyFuncToIwram' call.

ARM_FUNC __attribute__((flatten, noinline, no_reorder)) __attribute__((optimize("-O3"))) UNUSED static void DecodeSymtANSLoop(const u32 *data, u32 *ykTable, u16 *resultVec, u16 *resultVecEnd)
{
    u32 currBits = *data++;
    u32 bitIndex = sBitIndex;

    do
    {
        u32 symbol = 0;
        for (u32 currNibble = 0; currNibble < 4; currNibble++)
        {
            u32 ykVals = ykTable[sCurrState];
            symbol |= TABLE_READ_SYMBOL(ykVals) << (currNibble*4);
            u32 currK = TABLE_READ_K(ykVals);
            sCurrState = TABLE_READ_Y(ykVals);
            sCurrState += (currBits >> bitIndex) & TABLE_READ_MASK(ykVals);
            bitIndex += currK;
            if (bitIndex >= 32)
            {
                currBits = *data++;
                bitIndex -= 32;
                if (bitIndex != 0)
                {
                    sCurrState += (currBits & ((1u << bitIndex) - 1)) << (currK - bitIndex);
                }
            }
        }
        *resultVec++ = symbol;
    } while (resultVec < resultVecEnd);

    sBitIndex = bitIndex;
    sDataPtr = data - 1;
}

ARM_FUNC __attribute__((no_reorder)) static void SwitchToArmCallDecodeSymtANS(const u32 *data, u32 *ykTable, u16 *resultVec, u16 *resultVecEnd, void (*decodeFunction)(const u32 *data, u32 *ykTable, u16 *resultVec, u16 *resultVecEnd))
{
    decodeFunction(data, ykTable, resultVec, resultVecEnd);
}

static void DecodeSymtANS(const u32 *data, const u32 *pFreqs, u16 *resultVec, u32 count)
{
    BuildDecompressionTable(pFreqs, sWorkingYkTable);

    u32 funcBuffer[FUNC_BUFFER_SIZE(DecodeLOtANSLoop, SwitchToArmCallLOtANS)];
    // CopyFuncToIwram(funcBuffer, DecodeSymtANSLoop, SwitchToArmCallDecodeSymtANS);
    CopyFuncToIwram(funcBuffer, DecodeLOtANSLoop, SwitchToArmCallLOtANS);
    SwitchToArmCallDecodeSymtANS(data, sWorkingYkTable, resultVec, &resultVec[count], (void *) funcBuffer);
}

#define ANS_LOOP_MAIN(nibble)   \
{ \
    u32 ykVals = ykTable[sCurrState]; \
    currK = TABLE_READ_K(ykVals); \
    currSymbol = (currSymbol + TABLE_READ_SYMBOL(ykVals)) & 0xf; \
    symbol |= currSymbol << (nibble*4); \
    sCurrState = TABLE_READ_Y(ykVals); \
    sCurrState += ((currBits >> bitIndex) & TABLE_READ_MASK(ykVals)); \
    bitIndex += currK; \
}

//  Inner loop of tANS decoding for delta encoded symbol data, uses u16 data size
//  Basic process for decoding a tANS encoded value is to read the current symbol from the decoding table, then calculate the next state
//  from the y and k values for the current state and add the value read from the next k bits in the bitstream
ARM_FUNC __attribute__((flatten, noinline, no_reorder)) __attribute__((optimize("-O3"))) u32 DecodeSymDeltatANSLoop(const u32 *data, u32 *ykTable, u16 *resultVec, u16 *resultVecEnd)
{
    u32 currBits = *data++;
    u32 currSymbol = 0;
    u32 bitIndex = sBitIndex;
    u32 * resultVec_32 = (u32*)(resultVec); // Since we're doing 2 symbols at one time we store as word which is faster than storing two halfwords.

    do
    {
        u32 symbol = 0;
        u32 currK;

        {
            ANS_LOOP_MAIN(0);

            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                ANS_LOOP_MAIN(1);
                ANS_LOOP_MAIN(2);
                ANS_LOOP_MAIN(3);
                ANS_LOOP_MAIN(4);

                goto NIBBLE_5;
            }
        }
        {
            ANS_LOOP_MAIN(1);

            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                ANS_LOOP_MAIN(2);
                ANS_LOOP_MAIN(3);
                ANS_LOOP_MAIN(4);
                ANS_LOOP_MAIN(5);

                goto NIBBLE_6;
            }
        }
        {
            ANS_LOOP_MAIN(2);

            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                ANS_LOOP_MAIN(3);
                ANS_LOOP_MAIN(4);
                ANS_LOOP_MAIN(5);
                ANS_LOOP_MAIN(6);

                goto NIBBLE_7;
            }
        }
        {
            ANS_LOOP_MAIN(3);

            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                ANS_LOOP_MAIN(4);
                ANS_LOOP_MAIN(5);
                ANS_LOOP_MAIN(6);
                ANS_LOOP_MAIN(7);

                goto LOOP_STORE;
            }
        }
    NIBBLE_4:
        {
            ANS_LOOP_MAIN(4);

            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                ANS_LOOP_MAIN(5);
                ANS_LOOP_MAIN(6);
                ANS_LOOP_MAIN(7);

                goto LOOP_STORE;
            }
        }
    NIBBLE_5:
        {
            ANS_LOOP_MAIN(5);

            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                ANS_LOOP_MAIN(6);
                ANS_LOOP_MAIN(7);

                goto LOOP_STORE;
            }
        }
    NIBBLE_6:
        {
            ANS_LOOP_MAIN(6);

            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                ANS_LOOP_MAIN(7);

                goto LOOP_STORE;
            }
        }
    NIBBLE_7:
        {
            ANS_LOOP_MAIN(7);

            if (bitIndex >= 32)
            {
                LOOP_BITADVANCE();

                *resultVec_32++ = (symbol);
                if (resultVec_32 >= (u32 *) resultVecEnd)
                    break;

                symbol = 0;

                ANS_LOOP_MAIN(0);
                ANS_LOOP_MAIN(1);
                ANS_LOOP_MAIN(2);
                ANS_LOOP_MAIN(3);

                goto NIBBLE_4;
            }
        }

    LOOP_STORE:
        *resultVec_32++ = (symbol);

    } while (resultVec_32 < (u32 *) resultVecEnd);
    sBitIndex = bitIndex;
    sDataPtr = data - 1;
    return currSymbol;
}

//  Dark Egg magic
ARM_FUNC __attribute__((no_reorder)) static u32 SwitchToArmCallSymDeltaANS(const u32 *data, u32 *ykTable, u16 *resultVec, u16 *resultVecEnd, u32 (*decodeFunction)(const u32 *data, u32 *ykTable, u16 *resultVec, u16 *resultVecEnd))
{
    return decodeFunction(data, ykTable, resultVec, resultVecEnd);
}

static void DecodeSymDeltatANS(const u32 *data, const u32 *pFreqs, u16 *resultVec, u32 count)
{
    BuildDecompressionTable(pFreqs, sWorkingYkTable);

    // We want to store in packs of 2, so count needs to be divisible by 2
    u32 remainingCount = count % 2;

    u32 funcBuffer[FUNC_BUFFER_SIZE(DecodeSymDeltatANSLoop, SwitchToArmCallSymDeltaANS)];
    CopyFuncToIwram(funcBuffer, DecodeSymDeltatANSLoop, SwitchToArmCallSymDeltaANS);
    u32 currSymbol = SwitchToArmCallSymDeltaANS(data, sWorkingYkTable, resultVec, &resultVec[count - remainingCount], (void *) funcBuffer);

    if (remainingCount)
    {
        u32 currK;
        u32 *ykTable = sWorkingYkTable;
        const u32 *data = sDataPtr;
        u32 currBits = *data++;
        u32 bitIndex = sBitIndex;
        u32 symbol = 0;

        ANS_LOOP_MAIN(0);
        if (bitIndex >= 32)
        {
            LOOP_BITADVANCE();

            ANS_LOOP_MAIN(1);
            ANS_LOOP_MAIN(2);
            ANS_LOOP_MAIN(3);

            goto LOOP_STORE;
        }

        ANS_LOOP_MAIN(1);
        if (bitIndex >= 32)
        {
            LOOP_BITADVANCE();

            ANS_LOOP_MAIN(2);
            ANS_LOOP_MAIN(3);

            goto LOOP_STORE;
        }

        ANS_LOOP_MAIN(2);
        if (bitIndex >= 32)
        {
            LOOP_BITADVANCE();

            ANS_LOOP_MAIN(3);

            goto LOOP_STORE;
        }

        ANS_LOOP_MAIN(3);

    LOOP_STORE:
        resultVec[count - remainingCount] = symbol;
        sBitIndex = bitIndex;
    }
}

static __attribute__((always_inline)) inline void Fill16(u16 value, void *_dst, u32 size)
{
    u16 *dst = _dst;
    for (u32 i = 0; i < size; i++) {
        dst[i] = value;
    }
}

static __attribute__((always_inline)) inline void Copy16(const void *_src, void *_dst, u32 size)
{
    const u16 *src = _src;
    u16 *dst = _dst;
    for (u32 i = 0; i < size; i++) {
        dst[i] = src[i];
    }
}

//  Function to decode the instructions into the actual decompressed data
//  Basic process:
//  Read length from the loVec, 1 or 2 bytes as indicated by the last bit in the first byte
//  Read offset from the loVec, 1 or 2 bytes as indicated by the last bit in the first byte
//  If length is not 0 and offset is not 1:
//      Insert the current value from the Symbol vector into current result position and advance symbol vector by 1
//      Copy <length> values from <offset> values back in the result vector
//  If length is not 0 and offser is 1:
//      Insert the current value from the Symbol vector into current result position <length> times, then advance symbol vector by 1
//  If length is 0:
//      Insert <offset> number of symbols from the symbol vector into the result vector and advance the symbol vector position by <offset>
ARM_FUNC __attribute__((flatten, noinline, no_reorder)) __attribute__((optimize("-O3"))) static void DecodeInstructions(u32 headerLoSize, const u8 *loVec, const u16 *symVec, u16 *dest)
{
    const u8 *loVecEnd = loVec + headerLoSize;
    do
    {
        u32 currOffset, currLength;

        if (loVec[0] & CONTINUE_BIT)
        {
            currLength = (loVec[0] & FIRST_LO_MASK) | (loVec[1] << 7);
            currOffset = loVec[2] & FIRST_LO_MASK;
            if (loVec[2] & CONTINUE_BIT)
            {
                currOffset |= loVec[3] << 7;
                loVec += 4;
            }
            else
            {
                loVec += 3;
            }
        }
        else
        {
            currLength = loVec[0] & FIRST_LO_MASK;
            currOffset = loVec[1] & FIRST_LO_MASK;

            if (loVec[1] & CONTINUE_BIT)
            {
                currOffset |= (loVec[2] << 7);
                loVec += 3;
            }
            else
            {
                loVec += 2;
            }
        }

        if (currLength != 0)
        {
            u16 symVecVal = *symVec;
            *dest++ = *symVec++;
            if (currOffset == 1)
            {
                Fill16(symVecVal, dest, currLength);
                dest += currLength;
            }
            else
            {
                // Copy16 is slower in this case.
                u16 *from = dest - currOffset;
                u16 *to = dest + currLength;
                do {
                    *dest++ = *from++;
                } while (dest != to);
            }
        }
        else
        {
            Copy16(symVec, dest, currOffset);
            dest += currOffset;
            symVec += currOffset;
        }
    } while (loVec < loVecEnd);
}

//  Dark Egg magic
ARM_FUNC __attribute__((no_reorder)) static void SwitchToArmCallDecodeInstructions(u32 headerLoSize, const u8 *loVec, const u16 *symVec, void *dest, void (*decodeFunction)(u32 headerLoSize, const u8 *loVec, const u16 *symVec, void *dest))
{
    decodeFunction(headerLoSize, loVec, symVec, dest);
}

//  Dark Egg magic
static void DecodeInstructionsIwram(u32 headerLoSize, const u8 *loVec, const u16 *symVec, void *dest)
{
    u32 funcBuffer[FUNC_BUFFER_SIZE(DecodeInstructions, SwitchToArmCallDecodeInstructions)];

    CopyFuncToIwram(funcBuffer, DecodeInstructions, SwitchToArmCallDecodeInstructions);
    SwitchToArmCallDecodeInstructions(headerLoSize, loVec, symVec, dest, (void *) funcBuffer);
}

//  Entrance point for smol compressed data
static void SmolDecompressData(const struct SmolHeader *header, const u32 *data, void *dest)
{
    //  This is apparently needed due to Game Freak sending bullshit down the decompression pipeline
    if (header->loSize == 0 || header->symSize == 0)
        return;
    const u8 *leftoverPos = (u8 *)data;

    sCurrState = header->initialState;

    u32 headerLoSize = header->loSize;
    u32 headerSymSize = header->symSize;

    const u32 *pLoFreqs = NULL;
    const u32 *pSymFreqs = NULL;

    //  Use different decoding flows depending on which mode the data is compressed with
    switch (header->mode)
    {
        case BASE_ONLY: // Used by .fastSmol, there is no encoding there, so we can quickly decode all the instructions and quit.
            DecodeInstructionsIwram(headerLoSize, leftoverPos + headerSymSize*2, (void *) leftoverPos, dest);
            return;
        case ENCODE_LO:
            pLoFreqs = &data[0];
            sDataPtr = &data[3];
            break;
        case ENCODE_DELTA_SYMS:
        case ENCODE_SYMS:
            pSymFreqs = &data[0];
            sDataPtr = &data[3];
            break;
        case ENCODE_BOTH:
        case ENCODE_BOTH_DELTA_SYMS:
            pLoFreqs = &data[0];
            pSymFreqs = &data[3];
            sDataPtr = &data[6];
            break;
    }

    bool32 loEncoded = isModeLoEncoded(header->mode);
    bool32 symEncoded = isModeSymEncoded(header->mode);
    bool32 symDelta = isModeSymDelta(header->mode);

    // Everything needs to be aligned.
    u32 alignedLoSize = header->loSize % 2 == 1 ? headerLoSize + 1 : headerLoSize;
    u32 alignedSymSize = header->symSize % 2 == 1 ? headerSymSize + 1 : headerSymSize;
    void *memoryAlloced = Alloc((alignedSymSize*2) + alignedLoSize);
    u16 *symVec = memoryAlloced;
    u8 *loVec = memoryAlloced + alignedSymSize*2;

    sBitIndex = 0;
    //  Decode tANS encoded LO data, mode 3, 4 and 5
    if (loEncoded)
    {
        DecodeLOtANS(sDataPtr, pLoFreqs, loVec, headerLoSize);
        leftoverPos += 12;
    }
    //  Decode tANS encoded symbol data, mode 1, 2, 4 and 5
    if (symEncoded)
    {
        //  Symbols are delta encoded, mode 2 and 5
        if (symDelta)
            DecodeSymDeltatANS(sDataPtr, pSymFreqs, symVec, headerSymSize);
        //  Symbols are not delta encoded, mode 1 and 4
        else
            DecodeSymtANS(sDataPtr, pSymFreqs, symVec, headerSymSize);
        leftoverPos += 12;
    }

    //  If not both of lo and sym data are tANS encoded, data that isn't entropy encoded exists
    //  This is stored after the 32-bit aligned bitstream
    if (loEncoded || symEncoded)
        leftoverPos += 4*header->bitstreamSize;

    //  Copy the not entropy encoded symbol data to the symbol buffer
    //  Symbol data is u16 aligned
    if (symEncoded == FALSE)
    {
        symVec = (void *) leftoverPos;
        leftoverPos += headerSymSize*2;
    }

    //  Copy the not entropy encoded lo data to the lo buffer
    //  Despite the individual lo values being u8 aligned, the entire vector for the u8 values is u16 aligned
    if (loEncoded == FALSE)
    {
        loVec = (void *) leftoverPos;
    }

    //  Actually decode the final data from loVec and symVec
    DecodeInstructionsIwram(headerLoSize, loVec, symVec, dest);

    Free(memoryAlloced);
}

ARM_FUNC __attribute__((flatten, noinline, no_reorder)) __attribute__((optimize("-O3"))) static void DeltaDecodeTileNumbers(u16 *tileNumbers, u32 arraySize)
{
    u32 prevVal = 0;
    u32 reminder = arraySize % 8;
    u16 *dst = tileNumbers + (arraySize - reminder);
    do
    {
        prevVal += *tileNumbers;
        *tileNumbers++ = prevVal;

        prevVal += *tileNumbers;
        *tileNumbers++ = prevVal;

        prevVal += *tileNumbers;
        *tileNumbers++ = prevVal;

        prevVal += *tileNumbers;
        *tileNumbers++ = prevVal;

        prevVal += *tileNumbers;
        *tileNumbers++ = prevVal;

        prevVal += *tileNumbers;
        *tileNumbers++ = prevVal;

        prevVal += *tileNumbers;
        *tileNumbers++ = prevVal;

        prevVal += *tileNumbers;
        *tileNumbers++ = prevVal;
    } while (tileNumbers != dst);

    for (u32 i = 0; i < reminder; i++)
    {
        prevVal += *tileNumbers;
        *tileNumbers++ = prevVal;
    }
}

ARM_FUNC __attribute__((no_reorder)) static void SwitchToArmCallDecodeTileNumbers(u16 *tileNumbers, u32 arraySize, void (*decodeFunction)(u16 *tileNumbers, u32 arraySize))
{
    decodeFunction(tileNumbers, arraySize);
}

static void SmolDecompressTilemap(const struct SmolTilemapHeader *header, const u32 *data, u16 *dest)
{
    u16 *deltaDest = dest;
    u32 loOffset = header->symSize*2 + 2*(header->symSize % 2);
    u8 *loVec = (u8 *)data;
    loVec = &loVec[loOffset];
    u16 *symVec = (u16 *)data;

    DecodeInstructionsIwram(header->tileNumberSize, loVec, symVec, dest);
    u32 arraySize = header->tilemapSize/2;

    u32 funcBuffer[FUNC_BUFFER_SIZE(DeltaDecodeTileNumbers, SwitchToArmCallDecodeTileNumbers)];

    CopyFuncToIwram(funcBuffer, DeltaDecodeTileNumbers, SwitchToArmCallDecodeTileNumbers);
    SwitchToArmCallDecodeTileNumbers(deltaDest, arraySize, (void *) funcBuffer);
}

//  Helper functions for determining modes
static bool32 isModeLoEncoded(enum CompressionMode mode)
{
    if (mode == ENCODE_LO
     || mode == ENCODE_BOTH
     || mode == ENCODE_BOTH_DELTA_SYMS)
        return TRUE;
    return FALSE;
}

static bool32 isModeSymEncoded(enum CompressionMode mode)
{
    if (mode == ENCODE_SYMS
     || mode == ENCODE_DELTA_SYMS
     || mode == ENCODE_BOTH
     || mode == ENCODE_BOTH_DELTA_SYMS)
        return TRUE;
    return FALSE;
}

static bool32 isModeSymDelta(enum CompressionMode mode)
{
    if (mode == ENCODE_DELTA_SYMS
     || mode == ENCODE_BOTH_DELTA_SYMS)
        return TRUE;
    return FALSE;
}

=======
>>>>>>> parent of 6e64f6f5ef (New sprite compressor (#5627))
void LoadSpecialPokePic(void *dest, s32 species, u32 personality, bool8 isFrontPic)
{
    species = SanitizeSpeciesId(species);
    if (species == SPECIES_UNOWN)
        species = GetUnownSpeciesId(personality);

    if (isFrontPic)
    {
    #if P_GENDER_DIFFERENCES
        if (gSpeciesInfo[species].frontPicFemale != NULL && IsPersonalityFemale(species, personality))
            LZ77UnCompWram(gSpeciesInfo[species].frontPicFemale, dest);
        else
    #endif
        if (gSpeciesInfo[species].frontPic != NULL)
            LZ77UnCompWram(gSpeciesInfo[species].frontPic, dest);
        else
            LZ77UnCompWram(gSpeciesInfo[SPECIES_NONE].frontPic, dest);
    }
    else
    {
    #if P_GENDER_DIFFERENCES
        if (gSpeciesInfo[species].backPicFemale != NULL && IsPersonalityFemale(species, personality))
            LZ77UnCompWram(gSpeciesInfo[species].backPicFemale, dest);
        else
    #endif
        if (gSpeciesInfo[species].backPic != NULL)
            LZ77UnCompWram(gSpeciesInfo[species].backPic, dest);
        else
            LZ77UnCompWram(gSpeciesInfo[SPECIES_NONE].backPic, dest);
    }

    if (species == SPECIES_SPINDA && isFrontPic)
    {
        DrawSpindaSpots(personality, dest, FALSE);
        DrawSpindaSpots(personality, dest, TRUE);
    }
}

void Unused_LZDecompressWramIndirect(const void **src, void *dest)
{
    LZ77UnCompWram(*src, dest);
}

static void UNUSED StitchObjectsOn8x8Canvas(s32 object_size, s32 object_count, u8 *src_tiles, u8 *dest_tiles)
{
    /*
      This function appears to emulate behaviour found in the GB(C) versions regarding how the Pokemon images
      are stitched together to be displayed on the battle screen.
      Given "compacted" tiles, an object count and a bounding box/object size, place the tiles in such a way
      that the result will have each object centered in a 8x8 tile canvas.
    */
    s32 i, j, k, l;
    u8 *src = src_tiles, *dest = dest_tiles;
    u8 bottom_off;

    if (object_size & 1)
    {
        // Object size is odd
        bottom_off = (object_size >> 1) + 4;
        for (l = 0; l < object_count; l++)
        {
            // Clear all unused rows of tiles plus the half-tile required due to centering
            for (j = 0; j < 8-object_size; j++)
            {
                for (k = 0; k < 8; k++)
                {
                    for (i = 0; i < 16; i++)
                    {
                        if (j % 2 == 0)
                        {
                            // Clear top half of top tile and bottom half of bottom tile when on even j
                            ((dest+i) + (k << 5))[((j >> 1) << 8)] = 0;
                            ((bottom_off << 8) + (dest+i) + (k << 5) + 16)[((j >> 1) << 8)] = 0;
                        }
                        else
                        {
                            // Clear bottom half of top tile and top half of tile following bottom tile when on odd j
                            ((dest+i) + (k << 5) + 16)[((j >> 1) << 8)] = 0;
                            ((bottom_off << 8) + (dest+i) + (k << 5) + 256)[((j >> 1) << 8)] = 0;
                        }
                    }
                }
            }

            // Clear the columns to the left and right that wont be used completely
            // Unlike the previous loops, this will clear the later used space as well
            for (j = 0; j < 2; j++)
            {
                for (i = 0; i < 8; i++)
                {
                    for (k = 0; k < 32; k++)
                    {
                        // Left side
                        ((dest+k) + (i << 8))[(j << 5)] = 0;
                        // Right side
                        ((dest+k) + (i << 8))[(j << 5)+192] = 0;
                    }
                }
            }

            // Skip the top row and first tile on the second row for objects of size 5
            if (object_size == 5) dest += 0x120;

            // Copy tile data
            for (j = 0; j < object_size; j++)
            {
                for (k = 0; k < object_size; k++)
                {
                    for (i = 0; i < 4; i++)
                    {
                        // Offset the tile by +4px in both x and y directions
                        (dest + (i << 2))[18] = (src + (i << 2))[0];
                        (dest + (i << 2))[19] = (src + (i << 2))[1];
                        (dest + (i << 2))[48] = (src + (i << 2))[2];
                        (dest + (i << 2))[49] = (src + (i << 2))[3];

                        (dest + (i << 2))[258] = (src + (i << 2))[16];
                        (dest + (i << 2))[259] = (src + (i << 2))[17];
                        (dest + (i << 2))[288] = (src + (i << 2))[18];
                        (dest + (i << 2))[289] = (src + (i << 2))[19];
                    }
                    src += 32;
                    dest += 32;
                }

                // At the end of a row, skip enough tiles to get to the beginning of the next row
                if (object_size == 7) dest += 0x20;
                else if (object_size == 5) dest += 0x60;
            }

            // Skip remaining unused space to go to the beginning of the next object
            if (object_size == 7) dest += 0x100;
            else if (object_size == 5) dest += 0x1e0;
        }
    }
    else
    {
        // Object size is even
        for (i = 0; i < object_count; i++)
        {
            // For objects of size 6, the first and last row and column will be cleared
            // While the remaining space will be filled with actual data
            if (object_size == 6)
            {
                for (k = 0; k < 256; k++)
                {
                    *dest = 0;
                    dest++;
                }
            }

            for (j = 0; j < object_size; j++)
            {
                if (object_size == 6)
                {
                    for (k = 0; k < 32; k++)
                    {
                        *dest = 0;
                        dest++;
                    }
                }

                // Copy tile data
                for (k = 0; k < 32 * object_size; k++)
                {
                    *dest = *src;
                    src++;
                    dest++;
                }

                if (object_size == 6)
                {
                    for (k = 0; k < 32; k++)
                    {
                        *dest = 0;
                        dest++;
                    }
                }
            }

            if (object_size == 6)
            {
                for (k = 0; k < 256; k++)
                {
                    *dest = 0;
                    dest++;
                }
            }
        }
    }
}

u32 GetDecompressedDataSize(const u32 *ptr)
{
    const u8 *ptr8 = (const u8 *)ptr;
    return (ptr8[3] << 16) | (ptr8[2] << 8) | (ptr8[1]);
}

bool32 IsCompressedData(const u32 *ptr)
{
    u32 size;
    union CompressionHeader *header = (union CompressionHeader *)ptr;
    switch (header->smol.mode)
    {
    case MODE_LZ77:
        return IsLZ77Data(ptr, TILE_SIZE_4BPP, MAX_DECOMPRESSION_BUFFER_SIZE);
    case BASE_ONLY:
    case ENCODE_SYMS:
    case ENCODE_DELTA_SYMS:
    case ENCODE_LO:
    case ENCODE_BOTH:
    case ENCODE_BOTH_DELTA_SYMS:
        size = GetDecompressedDataSize(ptr);
        if (size % TILE_SIZE_4BPP == 0 && size < MAX_DECOMPRESSION_BUFFER_SIZE)
            return TRUE;
        break;
    case IS_FRAME_CONTAINER:
        // No implemented yet
    case IS_TILEMAP:
        // Has to use another assumption
    default:
        //  Is not one of these cases, it's not compressed data
        return FALSE;
    }
    return FALSE;
}

bool8 LoadCompressedSpriteSheetUsingHeap(const struct CompressedSpriteSheet *src)
{
    struct SpriteSheet dest;
    void *buffer;

    buffer = AllocZeroed(src->data[0] >> 8);
    LZ77UnCompWram(src->data, buffer);

    dest.data = buffer;
    dest.size = src->size;
    dest.tag = src->tag;

    LoadSpriteSheet(&dest);
    Free(buffer);
    return FALSE;
}
<<<<<<< HEAD

<<<<<<< HEAD
<<<<<<< HEAD
extern const u32 LZ77UnCompWRAMOptimized[];
extern const u32 LZ77UnCompWRAMOptimized_end[];

ARM_FUNC static void SwitchToArmCallFastLZ77(const u32 *src, void *dest, void (*funcPtr)(const u32 *src, void *dest))
{
    funcPtr(src, dest);
}

void FastLZ77UnCompWram(const u32 *src, void *dest)
{
    u32 funcBuffer[200];

    CopyFuncToIwram(funcBuffer, LZ77UnCompWRAMOptimized, LZ77UnCompWRAMOptimized_end);
    SwitchToArmCallFastLZ77(src, dest, (void *) funcBuffer);
=======
=======
>>>>>>> parent of 8cfe915bcd (Expansion 1.11.4 & 1.12.0 (#7026))
bool8 LoadCompressedSpritePaletteUsingHeap(const struct CompressedSpritePalette *src)
{
    struct SpritePalette dest;
    void *buffer;

    buffer = AllocZeroed(src->data[0] >> 8);
    LZ77UnCompWram(src->data, buffer);
    dest.data = buffer;
    dest.tag = src->tag;

    LoadSpritePalette(&dest);
    Free(buffer);
    return FALSE;
<<<<<<< HEAD
>>>>>>> parent of 09ee1d0b2d (Merge branch 'upcoming' into expansion-1.11.4)
=======
>>>>>>> parent of 8cfe915bcd (Expansion 1.11.4 & 1.12.0 (#7026))
}
=======
>>>>>>> parent of 6e64f6f5ef (New sprite compressor (#5627))
