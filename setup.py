from setuptools import setup
from torch.utils.cpp_extension import BuildExtension, CUDAExtension

setup(
    name='paperP',
    ext_modules=[
        CUDAExtension('paper_module', [
            'deviceAnalyticVolume.cpp',
            'deviceAnalyticVolume.cu',
            'deviceOverlay.cpp',
            'deviceOverlay.cu',
            'hostAnalyticVolume.cpp',
            'hostAnalyticVolume.cu',
            'inputModule.cpp',
            'inputModule.cu',
            'transformTools.cpp',
            'transformTools.cu',
            'paper.cpp',
            'paper.cu',

            'inputFileReader.cpp',
            'inputPreprocessor.cpp',

            'paper_api.cpp',
        ],

        extra_compile_args={'cxx': ['-g'],
                            'nvcc': ['-02']})
    ],
    cmdclass={'build_ext': BuildExtension}
)
