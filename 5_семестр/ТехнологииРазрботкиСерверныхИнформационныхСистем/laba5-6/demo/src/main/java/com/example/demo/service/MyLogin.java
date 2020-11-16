package com.example.demo.service;

import com.example.demo.db.model.User;
import org.springframework.security.core.authority.AuthorityUtils;

public class MyLogin extends org.springframework.security.core.userdetails.User {

    private User user;

    public MyLogin(User user) {
        super(user.getLogin(), user.getPassHash(), AuthorityUtils.createAuthorityList("ALL")); // роль
        this.user = user;
    }
}