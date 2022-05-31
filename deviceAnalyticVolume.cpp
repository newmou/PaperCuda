#include <cuda.h>
#include <torch/serialize/tensor.h>
#include <torch/extension.h>
#include <THC/THC.h>

#include "deviceAnalyticVolume.h"

extern THCState *state;

int transformToRotationMatrix_c(float* t,float* matrix){
    transformToRotationMatrix(t,matrix);
    return 1;
}

int transformMolecule_c(float* x,float* y,float* z,uint natoms,float* matrix,float* translation){
    transformMolecule(x,y,z,natoms,matrix,translation);
    return 1;
}

int getQuatGradients_c(float* x,float* y,float* z,uint ourfitcount,float* transform,float* dxdq,float* dxdr,float* dydr,float* dxdu){
    getQuatGradients(x,y,z,ourfitcount,transform,dxdq,dxdr,dydr,dxdu);
    return 1;
}

int deviceOverlapVolume_c(float* fitmols,uint* fitatomcount,size_t fitmol_pitch,
                                    float* refmol ,uint  refatomcount,size_t refmol_pitch,
                                    float* transforms,size_t transform_pitch,
                                    float* finalOverlaps){
    deviceOverlapVolume(fitmols,fitatomcount,fitmol_pitch,refmol,refatomcount,refmol_pitch,transforms,transform_pitch,finalOverlaps);
    return 1;
                                    }

int deviceOverlapAndGradient_c(float* fitmols,uint* fitatomcount,size_t fitmol_pitch,
                                         float* refmol ,uint  refatomcount,size_t refmol_pitch,
                                         float* transforms,size_t transform_pitch,
                                         float* finalOverlapsAndGradients,size_t gradient_pitch){
    deviceOverlapAndGradient(fitmols,fitatomcount,fitmol_pitch,refmol,refatomcount,refmol_pitch,transforms,transform_pitch,finalOverlapsAndGradients,gradient_pitch);
    return 1;
                                         }