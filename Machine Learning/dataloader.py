from email import iterators
from sklearn import datasets
import torch
import torch.nn as nn
import torchvision
from torch.utils.data import Dataset, DataLoader
import numpy as np
import math

class WineDataset(Dataset):

    def __init__(self):
        # Initialize data, download, etc.
        # read with numpy or pandas
        xy = np.loadtxt('./data/wine/wine.csv', delimiter=',', dtype=np.float32, skiprows=1)
        self.n_samples = xy.shape[0]

        # here the first column is the class label, the rest are the features
        self.x_data = torch.from_numpy(xy[:, 1:]) # size [n_samples, n_features]
        self.y_data = torch.from_numpy(xy[:, [0]]) # size [n_samples, 1]

    # support indexing such that dataset[i] can be used to get i-th sample
    def __getitem__(self, index):
        return self.x_data[index], self.y_data[index]

    # we can call len(dataset) to return the size
    def __len__(self):
        return self.n_samples


# create dataset
dataset = WineDataset()

# get first sample and unpack
first_data = dataset[0]
features, labels = first_data
print(features, labels)

# Load whole dataset with DataLoader
# shuffle: shuffle data, good for training
# num_workers: faster loading with multiple subprocesses
# !!! IF YOU GET AN ERROR DURING LOADING, SET num_workers TO 0 !!!
dataloader = DataLoader(dataset=dataset,
                          batch_size=4,
                          shuffle=True,
                          num_workers=2)

#Hàm iter () trong Python trả về một trình vòng lặp cho đối tượng đã cho.
'''
# list of vowels
vowels = ['a', 'e', 'i', 'o', 'u']
vowels_iter = iter(vowels)

print(next(vowels_iter))    # 'a'
print(next(vowels_iter))    # 'e'
print(next(vowels_iter))    # 'i'
print(next(vowels_iter))    # 'o'
print(next(vowels_iter))    # 'u'
'''
# convert to an iterator and look at one random sample
#dataiter = iter(train_loader)
#data = dataiter.next()
#features, labels = data
#print(features, labels)

#Training loop
num_epochs = 5
batch_size = 4
total_samples = len(dataset)
n_iterators = math.ceil(total_samples/batch_size) #ceil() la tron so
print(total_samples,n_iterators)


#enumerate()phương thức nhận hai tham số
#phương thức thêm bộ đếm vào một có thể lặp lại và trả về nó.
for epoch in range(num_epochs):
    for i,(inputs,labels) in enumerate(dataloader):
        #forward backward, update

        if(i+1)%5 == 0:
            print(f'epoch: {epoch+1}/{num_epochs}, step  {i+1}/{n_iterators}, inputs {inputs.shape}')
        
    
train_dataset = torchvision.datasets.MNIST(root='./data',
                            train= True,\
                            transform = torchvision.transforms.ToTensor(),
                            download = True)

train_loader = DataLoader(dataset=train_dataset,
                            batch_size=3,
                            shuffle=True)

# look at one random sample
dataiter = iter(train_loader)
data = dataiter.next()
inputs, targets = data
print(inputs.shape, targets.shape)
#fashion-nmist, cifar, coco
        









