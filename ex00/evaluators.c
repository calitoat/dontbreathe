/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:23:47 by icuz              #+#    #+#             */
/*   Updated: 2016/11/10 23:11:01 by icuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_myfunk.h"
#include "evaluators.h"

int	parse_atom(char **expr)
{
	int nbr;

	while (**expr == ' ')
		(*expr)++;
	if (**expr == '(')
	{
		(*expr)++;
		nbr = parse_summands(expr);
		if (**expr == ')')
			(*expr)++;
		return (nbr);
	}
	return (ft_atoi(expr));
}

int	parse_factor(char **expr)
{
	int  nb;
	int  nb2;
	char op;

	nb = parse_atom(expr);
	while (**expr)
	{
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '/' && op != '*' && op != '%')
			return (nb);
		(*expr)++;
		nb2 = parse_atom(expr);
		if (op == '/')
			nb /= nb2;
		else if (op == '*')
			nb *= nb2;
		else
		   	nb %= nb;
	}
	return (nb);
}

int	parse_summands(char **expr)
{
	int  nb;
	int  nb2;
	char op;

	nb = parse_factor(expr);
	while (**expr)
	{
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '+' && op!= '-')
			return (nb);
		(*expr)++;
		nb2 = parse_factor(expr);
		if (op == '+')
			nb += nb2;
		else
			nb -= nb2;
	}
	return (nb);
}

int eval_expr(char *expr)
{
	return (parse_summands(&expr));
}
