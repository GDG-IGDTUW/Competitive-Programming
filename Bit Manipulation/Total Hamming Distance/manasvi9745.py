def total_hamming_distance(nums):
    n = len(nums)
    total = 0

    for bit in range(32):  # up to 32 bits
        ones = 0
        
        for num in nums:
            if (num >> bit) & 1:
                ones += 1
        
        zeros = n - ones
        total += ones * zeros

    return total


# Example
print(total_hamming_distance([4, 14, 2]))  # Output: 6
