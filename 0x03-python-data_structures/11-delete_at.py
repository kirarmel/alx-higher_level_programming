def delete_at(my_list=[], idx=0):
    if 0 <= idx < len(my_list):
        # Create a new list without the item at index idx
        my_list = my_list[:idx] + my_list[idx+1:]
    return my_list
