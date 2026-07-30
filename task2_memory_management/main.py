from fifo import fifo
from lru import lru

pages = [7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2]
frame_size = 3

fifo(pages, frame_size)

print("\n" + "=" * 40)

lru(pages, frame_size)
