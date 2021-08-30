import numpy as np


coord = {
    "x" : 0,
    "y" : 120,
    "z" : 120
}

rrots = []
rsides = []
rots = []

highs = []
ws = []
a_s = []
ds = []
lows = []
high_corrs = []
print("tobler ===================================")
for i in range(5):
    rrot  = np.sqrt(np.square(coord["x"]) + np.square(coord["y"]))
    rside = np.sqrt(np.square(rrot) + np.square(coord["z"]))
    rot   = np.arcsin(coord["x"] / rrot)
    high = np.arcsin((rside * 0.5)/120) * 2

    low = 0

    if coord["z"] > 0:
        low =np.arccos(rrot / rside) + ((np.pi - high) / 2.0) - (np.pi / 2.0)
    else:
        low =-np.arccos(rrot / rside) + ((np.pi - high) / 2.0) - (np.pi / 2.0)

    high_corr = high + low
    rrots.append(rrot)
    rsides.append(rside)
    highs.append(high * 180 / np.pi)
    lows.append(low * 180 / np.pi)
    high_corrs.append(high_corr * 180 / np.pi)
##    coord["y"] += 40
    coord["z"] -= 60

print("     rrots  =", list(np.around(np.array(rrots),5)))
print("     rsides =", list(np.around(np.array(rsides),5)))


print("     highs  =", list(np.around(np.array(highs),5)))
print("      lows  =",list(np.around(np.array(lows),5)))
print("high_corrs  =",list(np.around(np.array(high_corrs),5)))