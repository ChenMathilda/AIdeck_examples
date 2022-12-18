#include "modelKernels.h"
L1_CL_MEM AT_L1_POINTER model_L1_Memory;
L2_MEM AT_L2_POINTER model_L2_Memory;
static AT_HYPERFLASH_FS_T HyperFlash;
void S1_Op_input_1_formatter(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out)

{
	/* Shared L1: 1568 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaW_Evt1;
	KerNormBW_fps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 784 [Tile0, 1:[28x28], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[28x28], 1]
		Tile0: [0, 784, 784], Tile1: [0, 784, 784], Tile2; [0, 784, 784]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 784 [Tile0, 1:[28x28], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[28x28], 1]
		Tile0: [0, 784, 784], Tile1: [0, 784, 784], Tile2; [0, 784, 784]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (unsigned char *__restrict__) (model_L1_Memory+0);
	KerArg0->Out = (signed char *__restrict__) (model_L1_Memory+784);
	KerArg0->W = (unsigned short int) (28);
	KerArg0->H = (unsigned short int) (28);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0), 784, 0, &DmaR_Evt1);
	AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read In */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		AT_FORK(gap_ncore(), (void *) CNN_NormBW_offset_fps, (void *) KerArg0);
		__CALL(CNN_NormBW_offset_fps, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+784), 784, 1, &DmaW_Evt1);
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S2_Conv2d_32x1x3x3_MaxPool_2x2_Relu(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		unsigned char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 20860 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaR_Evt3;
	AT_L2_EVENT DmaR_Evt4;
	AT_L2_EVENT DmaR_Evt5;
	AT_L2_EVENT DmaR_Evt6;
	AT_L2_EVENT DmaW_Evt1;
	KerSetBias_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerConv_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerPool_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 1, Tiled: 1]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 18432 [D1, [0 x 18432, 18432]][Tile0, 1:[12x12], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 18432, 18432]][Tile0, 1:[12x12], 4]
		Tile0: [0, 18432, 576], Tile1: [0, 18432, 576], Tile2; [0, 18432, 576]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 128 [D1, [0 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 128, 128]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 32 [D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 32 [D1, [0 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 32, 32]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 288 [D1, [0 x 288, 288]][D0, [0 x 288, 288]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 288, 288]][D0, [0 x 288, 288]]
		Tile0: [0, 288, 288], Tile1: [0, 288, 288], Tile2; [0, 288, 288]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 1152 [D1, [0 x 1152, 1152]][Tile0, 1:[6x6], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 1152, 1152]][Tile0, 1:[6x6], 1]
		Tile0: [0, 1152, 1152], Tile1: [0, 1152, 1152], Tile2; [0, 1152, 1152]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 784 [D0, [0 x 784, 784]][Tile0, 1:[28x25], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[28x25], 1][D0, [0 x 784, 784]]
		Tile0: [0, 784, 784], Tile1: [0, 784, 784], Tile2; [0, 784, 784]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 1:[9x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[9x1], 1]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Out = (int * __restrict__) (model_L1_Memory+2416);
	KerArg0->W = (unsigned short int) (12);
	KerArg0->H = (unsigned short int) (12);
	KerArg0->Feat = (unsigned short int) (32);
	KerArg0->Bias = (void * __restrict__) (model_L1_Memory+784);
	KerArg1->In = (signed char * __restrict__) (model_L1_Memory+0);
	KerArg1->W = (unsigned short int) (28);
	KerArg1->UsedW = (unsigned short int) (25);
	KerArg1->H = (unsigned short int) (28);
	KerArg1->InFeatures = (unsigned short int) (1);
	KerArg1->OutFeatures = (unsigned short int) (32);
	KerArg1->TotalInFeatures = (unsigned short int) (1);
	KerArg1->Filter = (signed char * __restrict__) (model_L1_Memory+976);
	KerArg1->Out = (int * __restrict__) (model_L1_Memory+2416);
	KerArg1->Pad = (v4s) 0;
	KerArg2->In = (int *__restrict__) (model_L1_Memory+2416);
	KerArg2->Out = (void *__restrict__) (model_L1_Memory+2416);
	KerArg2->Feat = (unsigned short int) (32);
	KerArg2->W = (unsigned short int) (12);
	KerArg2->H = (unsigned short int) (12);
	KerArg2->Scale = (unsigned char *__restrict__) (model_L1_Memory+912);
	KerArg2->ScaleN = (unsigned char *__restrict__) (model_L1_Memory+944);
	KerArg2->Infos = (signed char *__restrict__) (model_L1_Memory+20848);
	KerArg3->In = (signed char * __restrict__) (model_L1_Memory+2416);
	KerArg3->W = (unsigned short int) (12);
	KerArg3->UsedW = (unsigned short int) (12);
	KerArg3->H = (unsigned short int) (12);
	KerArg3->UsedH = (unsigned short int) (12);
	KerArg3->Feat = (unsigned short int) (32);
	KerArg3->Out = (signed char * __restrict__) (model_L1_Memory+1264);
	KerArg3->Pad = (v4s) 0;
	KerArg3->PoolMax = (unsigned char) (1);
	KerArg3->DoScale = (unsigned char) (0);
	KerArg3->Infos = (signed char * __restrict__) (model_L1_Memory+20848);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+784), 128, 0, &DmaR_Evt1);
	AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read Bias */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+912), 32, 0, &DmaR_Evt2);
	AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Scale */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+944), 32, 0, &DmaR_Evt3);
	AT_L2_WAIT(0, &DmaR_Evt3); /* Wait previous DMA read ScaleN */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+976), 288, 0, &DmaR_Evt4);
	AT_L2_WAIT(0, &DmaR_Evt4); /* Wait previous DMA read Filter */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0), 784, 0, &DmaR_Evt5);
	AT_L2_WAIT(0, &DmaR_Evt5); /* Wait previous DMA read In */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+20848), 9, 0, &DmaR_Evt6);
	AT_L2_WAIT(0, &DmaR_Evt6); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_D0_PROLOG =========================*/
			KerArg0->NormBias = (unsigned char) (((char *)(model_L1_Memory+20848))[5]);
			AT_FORK(gap_ncore(), (void *) KerParSetBiasB32_SQ8, (void *) KerArg0);
			__CALL(KerParSetBiasB32_SQ8, KerArg0);
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				KerArg1->UsedH = (unsigned short int) (25);
				AT_FORK(gap_ncore(), (void *) KerParConv3x3Stride2_SQ8, (void *) KerArg1);
				__CALL(KerParConv3x3Stride2_SQ8, KerArg1);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			AT_FORK(gap_ncore(), (void *) KerParReductIO_CC_SQ8, (void *) KerArg2);
			__CALL(KerParReductIO_CC_SQ8, KerArg2);
			AT_FORK(gap_ncore(), (void *) KerParPool2x2Stride2_ReLU_SQ8, (void *) KerArg3);
			__CALL(KerParPool2x2Stride2_ReLU_SQ8, KerArg3);
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+1264), 1152, 1, &DmaW_Evt1);
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S3_Conv2d_64x32x3x3_MaxPool_2x2_Relu(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		unsigned char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 24332 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaR_Evt3;
	AT_L2_EVENT DmaR_Evt4;
	AT_L2_EVENT DmaR_Evt5;
	AT_L2_EVENT DmaR_Evt6;
	AT_L2_EVENT DmaW_Evt1;
	KerSetBias_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerConv_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerPool_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Last;
	int T0Ind, T0Ind_Last;
	int D0Ind, D0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 64, Tiled: 1][Tile0 Dim: 1][D0 Dim: Init: 32, Tiled: 1]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 4096 [D1, [0 x 4096, 4096]][Tile0, 1:[4x4], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 4096, 4096]][Tile0, 1:[4x4], 4]
		Tile0: [0, 4096, 64], Tile1: [0, 4096, 64], Tile2; [0, 4096, 64]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 256 [D1, [0 x 256, 256]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 64 [D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 64 [D1, [0 x 64, 64]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 64, 64]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 18432 [D1, [0 x 18432, 18432]][D0, [0 x 18432, 18432]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 18432, 18432]][D0, [0 x 18432, 18432]]
		Tile0: [0, 18432, 18432], Tile1: [0, 18432, 18432], Tile2; [0, 18432, 18432]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 256 [D1, [0 x 256, 256]][Tile0, 1:[2x2], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [0 x 256, 256]][Tile0, 1:[2x2], 1]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 1152 [D0, [0 x 1152, 1152]][Tile0, 1:[6x6], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[6x6], 1][D0, [0 x 1152, 1152]]
		Tile0: [0, 1152, 1152], Tile1: [0, 1152, 1152], Tile2; [0, 1152, 1152]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 1:[9x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[9x1], 1]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Out = (int * __restrict__) (model_L1_Memory+20224);
	KerArg0->W = (unsigned short int) (4);
	KerArg0->H = (unsigned short int) (4);
	KerArg0->Feat = (unsigned short int) (64);
	KerArg0->Bias = (void * __restrict__) (model_L1_Memory+1152);
	KerArg1->In = (signed char * __restrict__) (model_L1_Memory+0);
	KerArg1->W = (unsigned short int) (6);
	KerArg1->UsedW = (unsigned short int) (6);
	KerArg1->H = (unsigned short int) (6);
	KerArg1->InFeatures = (unsigned short int) (32);
	KerArg1->OutFeatures = (unsigned short int) (64);
	KerArg1->TotalInFeatures = (unsigned short int) (32);
	KerArg1->Filter = (signed char * __restrict__) (model_L1_Memory+1536);
	KerArg1->Out = (int * __restrict__) (model_L1_Memory+20224);
	KerArg1->Pad = (v4s) 0;
	KerArg2->In = (int *__restrict__) (model_L1_Memory+20224);
	KerArg2->Out = (void *__restrict__) (model_L1_Memory+20224);
	KerArg2->Feat = (unsigned short int) (64);
	KerArg2->W = (unsigned short int) (4);
	KerArg2->H = (unsigned short int) (4);
	KerArg2->Scale = (unsigned char *__restrict__) (model_L1_Memory+1408);
	KerArg2->ScaleN = (unsigned char *__restrict__) (model_L1_Memory+1472);
	KerArg2->Infos = (signed char *__restrict__) (model_L1_Memory+24320);
	KerArg3->In = (signed char * __restrict__) (model_L1_Memory+20224);
	KerArg3->W = (unsigned short int) (4);
	KerArg3->UsedW = (unsigned short int) (4);
	KerArg3->H = (unsigned short int) (4);
	KerArg3->UsedH = (unsigned short int) (4);
	KerArg3->Feat = (unsigned short int) (64);
	KerArg3->Out = (signed char * __restrict__) (model_L1_Memory+19968);
	KerArg3->Pad = (v4s) 0;
	KerArg3->PoolMax = (unsigned char) (1);
	KerArg3->DoScale = (unsigned char) (0);
	KerArg3->Infos = (signed char * __restrict__) (model_L1_Memory+24320);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+1152), 256, 0, &DmaR_Evt1);
	AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read Bias */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+1408), 64, 0, &DmaR_Evt2);
	AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Scale */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+1472), 64, 0, &DmaR_Evt3);
	AT_L2_WAIT(0, &DmaR_Evt3); /* Wait previous DMA read ScaleN */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+1536), 18432, 0, &DmaR_Evt4);
	AT_L2_WAIT(0, &DmaR_Evt4); /* Wait previous DMA read Filter */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0), 1152, 0, &DmaR_Evt5);
	AT_L2_WAIT(0, &DmaR_Evt5); /* Wait previous DMA read In */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+24320), 9, 0, &DmaR_Evt6);
	AT_L2_WAIT(0, &DmaR_Evt6); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D1 */
		int D1Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_D0_PROLOG =========================*/
			KerArg0->NormBias = (unsigned char) (((char *)(model_L1_Memory+24320))[5]);
			AT_FORK(gap_ncore(), (void *) KerParSetBiasB32_SQ8, (void *) KerArg0);
			__CALL(KerParSetBiasB32_SQ8, KerArg0);
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1;
				/*====================== Call Kernel LOC_D0 =========================*/
				KerArg1->UsedH = (unsigned short int) (6);
				AT_FORK(gap_ncore(), (void *) KerParConv3x3Stride1_SQ8, (void *) KerArg1);
				__CALL(KerParConv3x3Stride1_SQ8, KerArg1);
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			AT_FORK(gap_ncore(), (void *) KerParReductIO_CC_SQ8, (void *) KerArg2);
			__CALL(KerParReductIO_CC_SQ8, KerArg2);
			AT_FORK(gap_ncore(), (void *) KerParPool2x2Stride2_ReLU_SQ8, (void *) KerArg3);
			__CALL(KerParPool2x2Stride2_ReLU_SQ8, KerArg3);
		} /* End iteration on Tile0 */
	} /* End iteration on D1 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+19968), 256, 1, &DmaW_Evt1);
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S4_Linear_10x2x2x64(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		unsigned char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 2904 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaR_Evt3;
	AT_L2_EVENT DmaR_Evt4;
	AT_L2_EVENT DmaR_Evt5;
	AT_L2_EVENT DmaR_Evt6;
	AT_L2_EVENT DmaW_Evt1;
	KerLinear_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last;
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 10, Tiled: 1][Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 256 [Tile0, 1:[1x1], 256]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 256]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Filter, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 2560 [D0, [0 x 2560, 2560]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 2560, 2560]]
		Tile0: [0, 2560, 2560], Tile1: [0, 2560, 2560], Tile2; [0, 2560, 2560]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 40 [D0, [0 x 40, 40]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 40, 40]]
		Tile0: [0, 40, 40], Tile1: [0, 40, 40], Tile2; [0, 40, 40]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 10 [D0, [0 x 10, 10]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 10, 10]]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 10 [D0, [0 x 10, 10]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 10, 10]]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 10 [D0, [0 x 10, 10]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 10, 10]]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 1:[1x1], 9]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x1], 9]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (signed char * __restrict__) (model_L1_Memory+0);
	KerArg0->Weights = (signed char * __restrict__) (model_L1_Memory+256);
	KerArg0->Bias = (void * __restrict__) (model_L1_Memory+2816);
	KerArg0->Out = (void * __restrict__) (model_L1_Memory+2856);
	KerArg0->InDim = (unsigned short int) (256);
	KerArg0->TotalInDim = (unsigned short int) (256);
	KerArg0->OutDim = (unsigned short int) (10);
	KerArg0->Scale = (unsigned char *__restrict__) (model_L1_Memory+2868);
	KerArg0->ScaleN = (unsigned char *__restrict__) (model_L1_Memory+2880);
	KerArg0->Infos = (signed char *__restrict__) (model_L1_Memory+2892);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0), 256, 0, &DmaR_Evt1);
	AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read In */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+256), 2560, 0, &DmaR_Evt2);
	AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Filter */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+2816), 40, 0, &DmaR_Evt3);
	AT_L2_WAIT(0, &DmaR_Evt3); /* Wait previous DMA read Bias */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+2868), 10, 0, &DmaR_Evt4);
	AT_L2_WAIT(0, &DmaR_Evt4); /* Wait previous DMA read Scale */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+2880), 10, 0, &DmaR_Evt5);
	AT_L2_WAIT(0, &DmaR_Evt5); /* Wait previous DMA read ScaleN */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+2892), 9, 0, &DmaR_Evt6);
	AT_L2_WAIT(0, &DmaR_Evt6); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1;
		{ /* Single iteration on Tile0 */
			int T0Ind_Last = 1;
			/*====================== Call Kernel LOC_LOOP =========================*/
			AT_FORK(gap_ncore(), (void *) KerParLinearLayerFullFeatB32_SQ8, (void *) KerArg0);
			__CALL(KerParLinearLayerFullFeatB32_SQ8, KerArg0);
		} /* End iteration on Tile0 */
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+2856), 10, 1, &DmaW_Evt1);
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S5_SoftMax(
		signed char * __restrict__ In,
		short int * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 44 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaW_Evt1;
	KerSoftMax_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 10 [Tile0, 1:[1x10], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x10], 1]
		Tile0: [0, 10, 10], Tile1: [0, 10, 10], Tile2; [0, 10, 10]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 20 [Tile0, 1:[1x10], 2]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x10], 2]
		Tile0: [0, 20, 20], Tile1: [0, 20, 20], Tile2; [0, 20, 20]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 1:[9x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[9x1], 1]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (signed char *__restrict__) (model_L1_Memory+0);
	KerArg0->N = (unsigned short int) (10);
	KerArg0->Out = (short int *__restrict__) (model_L1_Memory+12);
	KerArg0->Infos = (signed char *__restrict__) (model_L1_Memory+32);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0), 10, 0, &DmaR_Evt1);
	AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read In */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+32), 9, 0, &DmaR_Evt2);
	AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->Norm = (unsigned short int) (((char *)(model_L1_Memory+32))[0]);
		AT_FORK(gap_ncore(), (void *) KerParSoftMax_SQ8, (void *) KerArg0);
		__CALL(KerParSoftMax_SQ8, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+12), 20, 1, &DmaW_Evt1);
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
int modelCNN_Construct()

{
	AT_HYPERFLASH_FS_FC_EVENT UchanHF1;
	AT_HYPERFLASH_FS_CONF_T HyperFlashConf;
	int Error;
	AT_HYPERFLASH_FS_CONF_INIT(&HyperFlashConf, AT_MEM_L3_HFLASH, 0);
	AT_HYPERFLASH_FS_OPEN(&HyperFlash, &HyperFlashConf, "model_L3_Flash_Const.dat", &Error);
	if (Error) return 1;
	model_L2_Memory = (AT_L2_POINTER) AT_L2_ALLOC(0, 23901);
	if (model_L2_Memory == 0) return 3;
	model_L1_Memory = (AT_L1_POINTER) AT_L1_ALLOC(0, 24332);
	if (model_L1_Memory == 0) return 4;
	/* Moving S2_Infos, size 9 from HyperFlash at 21896 to (size 9) L2 at 21896..21904 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21896), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21896), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Weights, size 288 from HyperFlash at 20992 to (size 288) L2 at 20992..21279 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 20992), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 20992), 288, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Biases, size 128 from HyperFlash at 21536 to (size 128) L2 at 21536..21663 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21536), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21536), 128, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Mul_scale, size 32 from HyperFlash at 21832 to (size 32) L2 at 21832..21863 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21832), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21832), 32, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Mul_shift, size 32 from HyperFlash at 21864 to (size 32) L2 at 21864..21895 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21864), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21864), 32, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Infos, size 9 from HyperFlash at 21908 to (size 9) L2 at 21908..21916 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21908), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21908), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Weights, size 18432 from HyperFlash at 0 to (size 18432) L2 at 0..18431 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 0), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 0), 18432, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Biases, size 256 from HyperFlash at 21280 to (size 256) L2 at 21280..21535 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21280), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21280), 256, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Mul_scale, size 64 from HyperFlash at 21664 to (size 64) L2 at 21664..21727 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21664), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21664), 64, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Mul_shift, size 64 from HyperFlash at 21728 to (size 64) L2 at 21728..21791 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21728), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21728), 64, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Infos, size 9 from HyperFlash at 21920 to (size 9) L2 at 21920..21928 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21920), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21920), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Weights, size 2560 from HyperFlash at 18432 to (size 2560) L2 at 18432..20991 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 18432), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 18432), 2560, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Biases, size 40 from HyperFlash at 21792 to (size 40) L2 at 21792..21831 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21792), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21792), 40, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Mul_scale, size 10 from HyperFlash at 21932 to (size 10) L2 at 21932..21941 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21932), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21932), 10, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Mul_shift, size 10 from HyperFlash at 21944 to (size 10) L2 at 21944..21953 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21944), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21944), 10, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S5_Infos, size 9 from HyperFlash at 21956 to (size 9) L2 at 21956..21964 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 21956), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 21956), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	return 0;
}
int modelCNN_Destruct()

{
	AT_L2_FREE(0, model_L2_Memory, 23901);
	AT_L1_FREE(0, model_L1_Memory, 24332);
	AT_HYPERFLASH_FS_CLOSE(&HyperFlash);
	return 0;
}
unsigned int AT_GraphPerf[5];
unsigned int AT_GraphOperInfosNames[5] = {
	784,
	47232,
	296192,
	2560,
	10,
};
char *AT_GraphNodeNames[5] = {
	"S1_Op_input_1_formatter",
	"S2_Conv2d_32x1x3x3_MaxPool_2x2_Relu",
	"S3_Conv2d_64x32x3x3_MaxPool_2x2_Relu",
	"S4_Linear_10x2x2x64",
	"S5_SoftMax",
};
int modelCNN(
		unsigned char * __restrict__ Input_1,
		signed short * __restrict__ Output_1)

{
	AT_GraphPerf[0] = gap_cl_readhwtimer();
	S1_Op_input_1_formatter(
		((unsigned char * __restrict__) Input_1), /* In */
		((signed char * __restrict__) (model_L2_Memory+23120)) /* Out */
	);
	AT_GraphPerf[0] = gap_cl_readhwtimer() - AT_GraphPerf[0];
	AT_GraphPerf[1] = gap_cl_readhwtimer();
	S2_Conv2d_32x1x3x3_MaxPool_2x2_Relu(
		((signed char * __restrict__) (model_L2_Memory+23120)), /* In */
		((signed char * __restrict__) (model_L2_Memory+20992)), /* Filter */
		((signed int * __restrict__) (model_L2_Memory+21536)), /* Bias */
		((signed char * __restrict__) (model_L2_Memory+21968)), /* Out */
		((unsigned char * __restrict__) (model_L2_Memory+21832)), /* Scale */
		((signed char * __restrict__) (model_L2_Memory+21864)), /* ScaleN */
		((signed char * __restrict__) (model_L2_Memory+21896)) /* Infos */
	);
	AT_GraphPerf[1] = gap_cl_readhwtimer() - AT_GraphPerf[1];
	AT_GraphPerf[2] = gap_cl_readhwtimer();
	S3_Conv2d_64x32x3x3_MaxPool_2x2_Relu(
		((signed char * __restrict__) (model_L2_Memory+21968)), /* In */
		((signed char * __restrict__) (model_L2_Memory+0)), /* Filter */
		((signed int * __restrict__) (model_L2_Memory+21280)), /* Bias */
		((signed char * __restrict__) (model_L2_Memory+23120)), /* Out */
		((unsigned char * __restrict__) (model_L2_Memory+21664)), /* Scale */
		((signed char * __restrict__) (model_L2_Memory+21728)), /* ScaleN */
		((signed char * __restrict__) (model_L2_Memory+21908)) /* Infos */
	);
	AT_GraphPerf[2] = gap_cl_readhwtimer() - AT_GraphPerf[2];
	AT_GraphPerf[3] = gap_cl_readhwtimer();
	S4_Linear_10x2x2x64(
		((signed char * __restrict__) (model_L2_Memory+23120)), /* In */
		((signed char * __restrict__) (model_L2_Memory+18432)), /* Filter */
		((signed int * __restrict__) (model_L2_Memory+21792)), /* Bias */
		((signed char * __restrict__) (model_L2_Memory+21968)), /* Out */
		((unsigned char * __restrict__) (model_L2_Memory+21932)), /* Scale */
		((signed char * __restrict__) (model_L2_Memory+21944)), /* ScaleN */
		((signed char * __restrict__) (model_L2_Memory+21920)) /* Infos */
	);
	AT_GraphPerf[3] = gap_cl_readhwtimer() - AT_GraphPerf[3];
	AT_GraphPerf[4] = gap_cl_readhwtimer();
	S5_SoftMax(
		((signed char * __restrict__) (model_L2_Memory+21968)), /* In */
		((signed short * __restrict__) Output_1), /* Out */
		((signed char * __restrict__) (model_L2_Memory+21956)) /* Infos */
	);
	AT_GraphPerf[4] = gap_cl_readhwtimer() - AT_GraphPerf[4];
	return 0;
}
