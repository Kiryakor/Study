package com.example.demo.db.model;

import javax.persistence.*;
import lombok.Data;

@Entity
@Table(name = "USR")
@Data
public class User {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "USR_id", nullable = false, updatable = false)
    private Long id;

    @Column(name = "USR_login", nullable = false)
    private String login;

    @Column(name="USR_pass_hash", nullable = false)
    private String passHash;

    public String getLogin() {
        return  login;
    }

    public String getPassHash() {
        return  passHash;
    }
}