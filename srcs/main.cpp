/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:14:39 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/13 14:03:16 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"
#include "../includes/Enemy.hpp"
#include "../includes/World.hpp"

#include <ncurses.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

# define UP 119
# define DOWN 115
# define WALL '#'
# define PLAYER '>'

// enum colide = {"#", "", "", "", ""};

// void winsize(int *y, int *x){
// 	getmaxyx(stdscr, (*y), (*x));
// }

void		draw_grid(WINDOW *win, World *world){

    for (int y = 0; y < W_Y; y++)
        for (int x = 0; x < W_X; x++)
	        mvwaddch(win, y, x, world->getCharGrid(y, x));

}

// bool		collision(WINDOW *win, int pos_y, int pos_x) {


// 	int	mvch = mvwinch(win, pos_y, pos_x);

// 	return ( mvch == WALL ?  true : false);
// }

bool duration(std::clock_t *_start)
{
    std::clock_t duration = (std::clock() - *_start);

    if (duration > 60000)
    {
        *_start = std::clock();
        return true;
    }
    return false;
}

int main(void) {

	initscr();
	cbreak();
	noecho();
    curs_set(0);

	int		keycode;
	struct timespec ts;
    std::srand(0);

    Player *player = new Player("John");
    Enemy *enemy[NB_ENMY];
    for (int i = 0; i < NB_ENMY; i++)
        enemy[i] = new Enemy("Spaceship");
    World *world = new World(*player, enemy);

	ts.tv_sec = 0;
	ts.tv_nsec = 50 * 1000 * 1000;

	WINDOW *win = newwin(40, 150, 0, 0);

	keypad(win, TRUE);
	nodelay(win, TRUE);


	std::clock_t c_start = std::clock();

    std::srand(0);
	while (1)
	{
		if (duration(&c_start)) {
			wclear(win);
			box(win, 0, 0);
			draw_grid(win, world);
            if (player->getHealth() <= 0)
            {
                wprintw(win, "GAME OVER");
                wrefresh(win);
                sleep(100);
            }
            world->makeTheRules();
			wrefresh(win);

		}
		if ((keycode = wgetch(win)) == ERR)
			continue;
		else if (keycode == 'w')
               player->decremYPosition();
        else if (keycode == 's')
               player->incremYPosition();
		else if(keycode == 'e')
            player->fireProjectile(player->getYPosition(), player->getXPosition());
		else if (keycode == 'd')
		{
			// if (!collision(win, pos_y, pos_x + 1))
            // 	pos_x++;
		}
	}
	endwin();
	return 0;
}