#include <cuda.h>
#include <torch/serialize/tensor.h>
#include <torch/extension.h>
#include <THC/THC.h>

#include "deviceOverlay.h"

extern THCState *state;

int optimize_sepkernels_c(dCUDAMultimol d_fitmols, dCUDAMultimol d_refMultimol, float* finalScores, clock_t *h_timers, const uint numTimers,const float3 com_ref,const float3* com_fit){
    optimize_sepkernels(d_fitmols,d_refMultimol,finalScores,h_timers,numTimers,com_ref,com_fit);
    return 1;
}
