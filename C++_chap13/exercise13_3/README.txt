Conclusion:
When we copy a StrBlob, the underlying smart pointer is copyed. But the vector to which the pointer pointed is not copyed, which means both StrBlob objects will use the same vector. This may not be what we want.
When we copy a StrBlobPtr, the same thing happens as copying a StrBlob, but this may be what we want.
