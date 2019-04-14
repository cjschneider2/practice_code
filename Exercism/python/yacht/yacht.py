# Score categories
YACHT = 1
ONES = 2
TWOS = 3
THREES = 4
FOURS = 5
FIVES = 6
SIXES = 7
FULL_HOUSE = 8
FOUR_OF_A_KIND = 9
LITTLE_STRAIGHT = 10
BIG_STRAIGHT = 11
CHOICE = 12


def score_single(dice, number):
    return dice.count(number) * number


def score_yacht(dice):
    if dice.count(dice[0]) == 5:
        return 50
    else:
        return 0


def score_full_house(dice):
    cnt = []
    for i in range(1, 7):
        c = dice.count(i)
        if c >= 2:
            cnt.append((i, c))
    if len(cnt) != 2:
        return 0
    d1, c1 = cnt[0]
    d2, c2 = cnt[1]
    if c1 == c2:
        return 0
    return d1 * c1 + d2 * c2


def score_four_of_a_kind(dice):
    for i in range(1, 7):
        if dice.count(i) >= 4:
            return i * 4
    return 0


def score_little_straight(dice):
    dice = sorted(dice)
    for idx, die in enumerate(dice, 1):
        if idx != die:
            return 0
    return 30


def score_big_straight(dice):
    dice = sorted(dice)
    for idx, die in enumerate(dice, 2):
        if idx != die:
            return 0
    return 30


def score_choice(dice):
    return sum(dice)


def score(dice, category):
    if category == YACHT:
        return score_yacht(dice)
    elif category == ONES:
        return score_single(dice, 1)
    elif category == TWOS:
        return score_single(dice, 2)
    elif category == THREES:
        return score_single(dice, 3)
    elif category == FOURS:
        return score_single(dice, 4)
    elif category == FIVES:
        return score_single(dice, 5)
    elif category == SIXES:
        return score_single(dice, 6)
    elif category == FULL_HOUSE:
        return score_full_house(dice)
    elif category == FOUR_OF_A_KIND:
        return score_four_of_a_kind(dice)
    elif category == LITTLE_STRAIGHT:
        return score_little_straight(dice)
    elif category == BIG_STRAIGHT:
        return score_big_straight(dice)
    elif category == CHOICE:
        return score_choice(dice)
    else:
        return 0
