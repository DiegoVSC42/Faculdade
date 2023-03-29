import 'package:flutter/material.dart';

void main() {
  runApp(
    MaterialApp(
      debugShowCheckedModeBanner: true,
      //melhor que container
      home: Directionality(
        textDirection: TextDirection.ltr,
        child: Scaffold(
          backgroundColor: Colors.blueGrey[900],
          body: SafeArea(
            //minimum: EdgeInsets.symmetric(horizontal: 16, vertical: 32),
            child: Column(children: [
              Container(
                width: double.infinity,
                child: Padding(
                  padding: EdgeInsets.all(16),
                  child: Text(
                    "rad".toUpperCase(),
                    textAlign: TextAlign.left,
                    style: TextStyle(
                      color: Colors.grey[700],
                      fontSize: 25,
                    ),
                  ),
                ),
              ),
              Container(
                width: double.infinity,
                child: Padding(
                  padding: EdgeInsets.only(right: 16, bottom: 32),
                  child: Text(
                    "cos(π)",
                    textAlign: TextAlign.right,
                    style: TextStyle(
                      color: Colors.white,
                      fontSize: 75,
                    ),
                  ),
                ),
              ),
              Container(
                width: double.infinity,
                child: Padding(
                  padding: EdgeInsets.only(right: 16, bottom: 61),
                  child: Text(
                    "-1",
                    textAlign: TextAlign.right,
                    style: TextStyle(
                      color: Colors.grey[700],
                      fontSize: 50,
                    ),
                  ),
                ),
              ),
/*
####################################################################
              //PARTE DA CALCULADORA
####################################################################
*/
              Container(
                width: double.infinity,
                height: 480,
                color: Colors.black,
                child: Column(
                  children: [
                    //LINHA 1
                    Row(children: [
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.grey[900],
                        child: Center(
                          child: Text(
                            "7",
                            style: TextStyle(
                              color: Colors.grey[700],
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "inv".toUpperCase(),
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "deg".toUpperCase(),
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "%".toUpperCase(),
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                    ]),
                    //LINHA 2
                    Row(children: [
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.grey[900],
                        child: Center(
                          child: Text(
                            "4",
                            style: TextStyle(
                              color: Colors.grey[700],
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "sin",
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "cos",
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "tan",
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                    ]),
                    //LINHA 3
                    Row(children: [
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.grey[900],
                        child: Center(
                          child: Text(
                            "1",
                            style: TextStyle(
                              color: Colors.grey[700],
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "ln",
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "log",
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "√",
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                    ]),
                    //LINHA 4
                    Row(children: [
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.grey[900],
                        child: Center(
                          child: Text(
                            "0",
                            style: TextStyle(
                              color: Colors.grey[700],
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "π",
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "e",
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                      Container(
                        height: 120,
                        width: 98,
                        color: Colors.blue[900],
                        child: Center(
                          child: Text(
                            "^",
                            style: TextStyle(
                              color: Colors.white,
                              fontSize: 37.5,
                            ),
                          ),
                        ),
                      ),
                    ]),
                  ],
                ),
              ),
            ]),
          ),
        ),
      ),
    ),
  );
}
