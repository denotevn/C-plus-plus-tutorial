from more_itertools import sample
from sklearn import datasets
from sklearn.utils import shuffle
import torch
import torch.nn as nn
import torchvision
import torchvision.transforms as transforms
import matplotlib.pyplot as plt
from torch.utils.data import Dataset, DataLoader

#device configuration 
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu') 

#hyber parameters
input_size = 784 # 28 x 28
hidden_size  = 100
num_classes = 10
num_epochs = 5
batch_size = 100
learning_rate = 0.01

# MNIST dataset
train_dataset = torchvision.datasets.MNIST(root= './data',train = True,
                                        transform = transforms.ToTensor(), download = True)
test_dataset = torchvision.datasets.MNIST(root = './data',train = False,
                                        transform = transforms.ToTensor(), download = True)

# Data loader
train_loader = DataLoader(datasets = train_dataset, 
                                           batch_size = batch_size, 
                                           shuffle=True)
test_loader = DataLoader(datasets = test_dataset,
                                         batch_size = batch_size,
                                          shuffle = True)

examples = iter(train_loader)
samples, labels = examples.next()
print(samples.shape, labels.shape)





