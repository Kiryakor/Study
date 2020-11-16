package com.example.demo.helpers;

import com.example.demo.model.Model;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

public class JsonParser {
    static public Model.DataMoney postMoney(String response) throws JSONException {
        JSONObject newData = new JSONObject(response);
        String href = newData.getString("href");
        int price = newData.getInt("price");
        int count = newData.getInt("count");
        String name = newData.getString("name");

        return new Model.DataMoney(href,price,count,name);
    }

    static public JSONObject getAllMoney(ArrayList<Model.DataMoney> data) throws JSONException {
        JSONArray ar = new JSONArray();
        JSONObject obj = new JSONObject();
        for (int i=0;i<data.size();i++){
            ar.put(JsonParser.getMoney(data.get(i)));
        }
        obj.put("money",ar);
        return obj;
    }

    static public JSONObject getMoney(Model.DataMoney data) throws JSONException {
        JSONObject resultJson = new JSONObject();

        resultJson.put("count",data.getCount());
        resultJson.put("href",data.getHref());
        resultJson.put("price",data.getPrice());
        resultJson.put("name",data.getName());

        return  resultJson;
    }
}
