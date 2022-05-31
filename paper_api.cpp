#include <torch/serialize/tensor.h>
#include <torch/extension.h>
#include <pybind11/include/pybind11>

#include "inputModule.h"
#include "cudaVolumeTypes.h"
#include "hostAnalyticVolume.h"
#include "deviceAnalyticVolume.h"
#include "deviceOverlay.h"
#include "transformTools.h"
#include "paper.h"

PYBIND11_MODULE(TORCH_EXTENSION_NAME,m){
    m.def("paper_p",&paper_c,"paper_p");

    m.def("transformToRotationMatrix_p",&transformToRotationMatrix_c,"transformRotationMatrix_p");
    m.def("transformMolecule_p",&transformMolecule_c,"transformMolecule_p");
    m.def("getQuatGradients_p",&getQuatGradients_c,"getQuatGradients_p");
    m.def("deviceOverlapVolume_p",&deviceOverlapVolume_c,"deviceOverlapVolume_p");
    m.def("deviceOverlapAndGradient_p",&deviceOverlapAndGradient_c,"deviceOverlapAndGradient_p");

    m.def("optimize_sepkernels_p",&optimize_sepkernels_c,"optimize_sepkernels_p");

    m.def("hostOverlapVolume_p",&hostOverlapVolume_c,"hostOverlapVolume_p");
    m.def("hostOverlapVolumeAnalytic2_p",&hostOverlapVolumeAnalytic2_c,"hostOverlapVolumeAnalytic2_p");
    m.def("hostOverlapVolumeHS_p",&hostOverlapVolumeHS_c,"hostOverlapVolumeHS_p");
    m.def("hostQuatGradients_p",&hostQuatGradients_c,"hostQuatGradients_p");
    m.def("hostGradient_p",&hostGradient_c,"hostGradient_p");
    m.def("transformCUDAmolToHost_p",&transformCUDAmolToHost_c,"transformCUDAmolToHost_p");

    m.def("loadMolecules_p",&loadMolecules_c,"loadMolecules_p");

    m.def("affineQuatToMatrix_p",&affineQuatToMatrix_c,"affineQuatToMatrix_p");
    m.def("printTransformMatrix_p",&printTransformMatrix_c,"printTransformMatrix_c");
    m.def("composeTransform_p",&composeTransform_c,"composeTransform_p");
    m.def("transformToCompensatedMatrix_p",&transformToCompensatedMatrix_c,"transformToCompensatedMatrix_p");
    m.def("transformSinglePoint_p",&transformSinglePoint_c,"transformSinglePoint_p");



}