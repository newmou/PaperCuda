OBPATH=/usr/include/openbabel-2.0
CCFLAGS=-O2 -I$(OBPATH) -DORIG_GLOBAL -DFAST_OVERLAP -DNO_DIV_ADDRESS
LDFLAGS=-lopenbabel
PTXFLAGS=-Xcompiler -O2 -arch sm_11 -Xptxas -v
all: paper 
clean:
	rm -f paper *.linkinfo *.cu.cpp *.i *.ii *.cubin *.ptx *cudafe* *.o *.fatbin.c *.hash

paper: paper.o deviceAnalyticVolume.o hostAnalyticVolume.o deviceOverlay.o transformTools.o inputFileReader.o inputPreprocessor.o inputModule.o
	nvcc $(LDFLAGS) -O3 -o paper paper.o deviceAnalyticVolume.o hostAnalyticVolume.o deviceOverlay.o transformTools.o inputPreprocessor.o inputFileReader.o inputModule.o

paper.o: paper.cu
	nvcc $(CCFLAGS) -c paper.cu
deviceAnalyticVolume.o: deviceAnalyticVolume.cu
	nvcc $(CCFLAGS) $(PTXFLAGS) -c deviceAnalyticVolume.cu
hostAnalyticVolume.o: hostAnalyticVolume.cu
	nvcc $(CCFLAGS) -c hostAnalyticVolume.cu
inputModule.o: inputModule.cu transformTools.cu config_input.h inputModule.h
	nvcc $(CCFLAGS) -c inputModule.cu
deviceOverlay.o: deviceOverlay.cu config_algo.h config_input.h
	nvcc $(CCFLAGS) $(PTXFLAGS) -c deviceOverlay.cu
transformTools.o: transformTools.cu
	nvcc $(CCFLAGS) -c transformTools.cu
inputFileReader.o: inputFileReader.cpp inputFileReader.h
	g++ -DGPP $(CCFLAGS) -c inputFileReader.cpp
inputPreprocessor.o: inputPreprocessor.cpp inputPreprocessor.h
	g++ -DGPP $(CCFLAGS) -c inputPreprocessor.cpp
