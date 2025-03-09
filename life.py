import os
import random
import time

random.seed(30)

class Cell:
    def __init__(self, state=False, neighbor_count = 0):
        self.state = state
        self.neighbor_count = neighbor_count

    def is_alive(self):
        return self.state

    def set_state(self, state):
        self.state = state


class Grid:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.cells = [[Cell() for _ in range(width)] for _ in range(height)]

    def get_cell(self, x, y):
        return self.cells[y][x]

    def set_cell(self, x, y, state):
        self.cells[y][x].set_state(state)

    def count_neighbors(self, x, y):
        count = 0
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                if dx == 0 and dy == 0:
                    continue
                nx, ny = (x + dx) % self.width, (y + dy) % self.height
                if self.get_cell(nx, ny).is_alive():
                    count += 1
        return count

def display(grid):
    for y in range(grid.height):
        for x in range(grid.width):
            print('■' if grid.get_cell(x, y).is_alive() else '□', end='')
        print()
    print()

def apply_rules(cell):
    if cell.is_alive():
        return 2 <= cell.neighbor_count <= 3
    else:
        return cell.neighbor_count == 3
        
if __name__ == "__main__":
    width = 20
    height = 20
    iterations = 50

    grid = Grid(20, 20)

    probability = 0.3
    for y in range(grid.height):
        for x in range(grid.width):
            grid.set_cell(x, y, random.random() < probability)

    delay = 0.1
    for _ in range(iterations):
        os.system('clear')
        display(grid)

        new_grid = Grid(grid.width, grid.height)
        for y in range(grid.height):
            for x in range(grid.width):
                cell = grid.get_cell(x, y)
                cell.neighbor_count = grid.count_neighbors(x, y)
                new_state = apply_rules(cell)
                new_grid.set_cell(x, y, new_state)
        grid = new_grid

        time.sleep(delay)
