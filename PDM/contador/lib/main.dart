import 'package:flutter/material.dart';

void main() {
  runApp(
    Container(
      child: Center(
        child: Text(
          'Testando o Flutter',
          textDirection: TextDirection.ltr,
          style: TextStyle(
            color: Colors.blue,
          ),
        ),
      ),
    ),
  );
}
