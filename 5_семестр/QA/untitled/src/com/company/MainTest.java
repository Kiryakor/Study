package com.company;

import org.junit.Assert;
import org.junit.jupiter.api.Test;

import java.util.LinkedList;

class MainTest {

    @org.junit.jupiter.api.Test
    void Test_checkData_1() {
        Boolean result = Main.checkData("4+5");
        Assert.assertEquals(true,result);
    }

    @org.junit.jupiter.api.Test
    void action_1(){
        String line = Main.action("5+5+1-2");
        Assert.assertEquals("9",line);
    }

    @org.junit.jupiter.api.Test
    void isNumeric() {
        boolean value = Main.isNumeric('2');
        Assert.assertEquals(true,value);
    }

    @org.junit.jupiter.api.Test
    void parseData() {
        Pair<LinkedList<Integer>, LinkedList<String>> parse = Main.parseData("5+6");

        LinkedList<Integer> frs = new LinkedList<Integer>();
        frs.add(5);
        frs.add(6);

        LinkedList<String> scd = new LinkedList<String>();
        scd.add("+");
        Pair<LinkedList<Integer>, LinkedList<String>> eq = new Pair(frs,scd);

        Assert.assertEquals(eq.t,parse.t);
        Assert.assertEquals(eq.u,parse.u);
    }
}