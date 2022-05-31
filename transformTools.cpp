#include <cuda.h>
#include <torch/serialize/tensor.h>
#include <torch/extension.h>
#include <THC/THC.h>

#include "cudaVolumeTypes.h"
#include "transformTools.h"

extern THCState *state;

int affineQuatToMatrix_c(const float* quat,float* matrix){
    affineQuatToMatrix(quat,matrix);
    return 1;
}
int printTransformMatrix_c(const float* matrix,FILE* f){
    printTransformMatrix(matrix,f);
    return 1;
}

int composeTransform_c(float* a,const float* b){
    composeTransform(a,b);
    return 1;
}
int transformToCompensatedMatrix_c(float* transform,float3 com_ref,float3 com_fit){
    transformToCompensatedMatrix(transform,com_ref,com_fit);
    return 1;
}
int transformSinglePoint_c(const float* quat,const float3 point){
    transformSinglePoint(quat,point);
    return 1;
}