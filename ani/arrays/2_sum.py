def two_sum(nums, target):
    mp = {}  # value -> index
    
    for i, num in enumerate(nums):
        diff = target - num
        
        if diff in mp:
            return [mp[diff], i]  # Found the pair
        
        mp[num] = i  # Store index of current number

    return []  # If no pair found

# Example:
print(two_sum([2,7,11,15], 9))  # Output: [0,1]
