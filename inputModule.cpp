#include <cuda.h>
#include <torch/serialize/tensor.h>
#include <torch/extension.h>
#include <THC/THC.h>

#include "inputModule.h"

extern THCState *state;

int loadMolecules_c(int argc,char** argv,
                              CUDAmol** fitmols,CUDAmol& refmol,uint** molids,float** transforms,size_t& transform_pitch,
                              dCUDAMultimol& hostFitMM,dCUDAMultimol& devFitMM,
                              dCUDAMultimol& hostRefMM,dCUDAMultimol& devRefMM,
                              float3& com_ref,float3** com_fit,
                              uint& totalMols,uint& distinctMols){
    loadMolecules(argc,argv,fitmols,refmol,molids,transforms,transform_pitch,hostFitMM,devFitMM,hostRefMM,devRefMM,com_ref,com_fit,totalMols,distinctMols);
    return 1;
                              }
