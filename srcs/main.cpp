/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:14:39 by fmaury            #+#    #+#             */
/*   Updated: 2019/01/12 14:51:02 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Player.hpp"
#include "../includes/Enemy.hpp"

int main()
{
    World *world = new World();
    Player *player = new Player("John", *world);
    Enemy *enemy = new Enemy("Spaceship", *world);


    return 0;
}