package com.example.demo.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;

@Service
public class LoggedUserDetailsService implements UserDetailsService {

    private final LoginService loginService;

    @Autowired
    public LoggedUserDetailsService(LoginService loginService) {
        this.loginService = loginService;
    }

    @Override
    public UserDetails loadUserByUsername(String login) throws UsernameNotFoundException {
        UserDetails details = loginService.loadUserByLogin(login);
        if (details != null) {
            return details;
        } else {
            throw new UsernameNotFoundException("Invalid user " + login);
        }
    }
}
