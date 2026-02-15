def winner_optimized(s):
    count0 = s.count('0')
    count1 = s.count('1')

    moves = min(count0, count1)

    if moves % 2 == 1:
        return "Positron"
    else:
        return "Negatron"
