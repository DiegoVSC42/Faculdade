import 'package:flutter/material.dart';
import 'package:instaclone/src/component/minha_app_bar.dart';

class UserHome extends StatelessWidget {
  const UserHome({super.key});

  PreferredSizeWidget _minhaBarra(String texto) {
    return MinhaAppBar(
      title: Text(
        texto,
        style: TextStyle(
          color: Colors.black,
          fontSize: 36,
        ),
      ),
      backgroundColor: Colors.white,
      elevation: 0,
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: _minhaBarra("Home"),
      body: Center(
        child: Text("TESTE"),
      ),
      // body: Center(child: Text('HOME', style: TextStyle(fontSize: 48))),
    );
  }
}
