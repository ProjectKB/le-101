/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vehicules.hpp                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 21:15:10 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 12:02:09 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VEHICULES_HPP

# define VEHICULES_HPP

# include <iostream>
# include <string>
# include <vector>

using namespace std;
using str = string;

class Vehicule
{
	protected:
		int m_price;

	public:
		Vehicule(int price);
		virtual ~Vehicule();

		virtual void	display() const;
		virtual int		nbr_wheels() const = 0;
};

class Car : public Vehicule
{
	protected:
		int m_doors;
		int m_wheels;

	public:
		Car(int prix, int portes);
		virtual ~Car();

		virtual void	display() const;
		virtual int		nbr_wheels() const;
};

class Motorcycle : public Vehicule
{
	protected:
		int m_speed;
		int m_wheels;

	public:
		Motorcycle(int prix, int speed);
		virtual ~Motorcycle();

		virtual void	display() const;
		virtual int		nbr_wheels() const;
};

void	present_vehicule(Vehicule const &v);

#endif
