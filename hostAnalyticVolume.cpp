#include <cuda.h>
#include <torch/serialize/tensor.h>
#include <torch/extension.h>
#include <THC/THC.h>

#include "hostAnalyticVolume.h"

extern THCState *state;

int hostOverlapVolume_c(const CUDAmol& ref,const CUDAmol& fit){
    hostOverlapVolume(ref,fit);
    return 1;
}

int hostOverlapVolumeAnalytic2_c(const CUDAmol& ref,const CUDAmol& fit){
    hostOverlapVolumeAnalytic2(ref,fit);
    return 1;
}

int hostOverlapVolumeHS_c(const CUDAmol& ref,const CUDAmol& fit){
    hostOverlapVolumeHS(ref,fit);
    return 0;
}

int hostQuatGradients_c(const CUDAmol& fit,float* transform,float3* qDers,float3* rDers,float3* sDers,float3* uDers){
    hostQuatGradients(fit,transform,qDers,rDers,sDers,uDers);
    return 1;
}

int hostGradient_c(const CUDAmol& ref,const CUDAmol& fit,float* transform,float* gradient){
    hostGradient(ref,fit,transform,gradient);
    return 1;
}

int transformCUDAmolToHost_c(CUDAmol& cmol,CUDAmol& newmol,float* transform){
    transformCUDAmolToHost(cmol,newmol,transform);
    return 1;
}