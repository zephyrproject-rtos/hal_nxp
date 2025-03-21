# Introduction

A composite device combines multiple independent functionalities by unifying its code into one implementation. For example, the single functionality code for CDC is provided in the CDC example and the single functionality code for MSC is provided in the MSC example. Creating the CDC+MSC composite device example requires combining the CDC example code and MSC example code into a single example.

Composite device descriptors are combined from the single-function device descriptors. There are two single-function devices. Each device has an interface descriptor in a configuration descriptor. If the composite device is combined using two single function devices, the interface descriptor of each device should be merged into the composite device configuration descriptor.

Implementing a composite device involves combining the descriptors and the functionalities of the single function devices.

