package com.example.demo.service;

import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UsernameNotFoundException;

public interface LoginService {
    public UserDetails loadUserByLogin(String string) throws UsernameNotFoundException;
}