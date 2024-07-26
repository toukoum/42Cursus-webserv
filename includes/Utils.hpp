/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lquehec <lquehec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:50:11 by lquehec           #+#    #+#             */
/*   Updated: 2024/07/26 14:36:13 by lquehec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "Logger.hpp"

/* WEBSERV EXCEPTION */
class WebservException : public std::exception
{
	private:
		int					_errno;
		Logger::LogLevel	_logLevel;
		std::string			_msg;
	public:
		WebservException(int errnoNum, const char *msg, ...);
		WebservException(Logger::LogLevel logLevel, const char *msg, ...);
		virtual ~WebservException(void) throw() {}
		virtual const char *what() const throw() { return _msg.c_str(); }
		Logger::LogLevel	getLogLevel(void) const { return _logLevel; }
};

/* UTILS */
void	printMsg(std::ostream &os, const char *msg, ...);

#endif // UTILS_HPP