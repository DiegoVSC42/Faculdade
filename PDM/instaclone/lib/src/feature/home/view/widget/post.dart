import 'package:flutter/material.dart';

class UserPost extends StatelessWidget {
  const UserPost({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.blue,
      body: Center(
        child: Text(
          'POST',
          style: TextStyle(
            fontSize: 48,
          ),
        ),
      ),
    );
  }
}
