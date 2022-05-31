import torch
from torch.autograd import Variable
from torch.autograd import Function
import torch.nn as nn
from typing import Tuple

import openbabel
#处理分子文件的库

import paper_module as paperPy

class GatherOperation(Function):

    @staticmethod
    def paper_use():
        conv = openbabel.OBConversion()
        conv.OpenInAndOutFiles("文件名字","转换后的文件名")
        rt()
        Outfile()
        #调用定义的函数进行计算

