import 'package:flutter/material.dart';
import 'package:instaclone/src/component/minha_app_bar.dart';

import 'bubble_stories.dart';

class UserHome extends StatelessWidget {
  const UserHome({super.key});

  PreferredSizeWidget _minhaBarra(String texto) {
    return MinhaAppBar(
      title: Row(
        children: [
          Expanded(
            child: Text(
              texto, //"app_name".i18n(),
              style: TextStyle(
                color: Colors.black,
                fontSize: 36,
                fontFamily: "Billabong",
              ),
            ),
          ),
          Padding(
            padding: const EdgeInsets.all(24.0),
            child: Icon(
              Icons.favorite_border_outlined,
              color: Colors.blue,
              size: 24.0,
            ),
          ),
          Padding(
            padding: const EdgeInsets.all(0.0),
            child: Icon(
              Icons.send,
              color: Colors.blue,
              size: 24,
            ),
          ),
        ],
      ),
      backgroundColor: Colors.white,
      elevation: 1,
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: _minhaBarra("Instagram"),
      body: Center(
        child: _stories(context),
      ),
      // body: Center(child: Text('HOME', style: TextStyle(fontSize: 48))),
    );
  }

  Widget _stories(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.only(top: 15),
      child: SizedBox(
        height: 100,
        child: ListView.separated(
          separatorBuilder: (context, index) => const SizedBox(width: 15),
          scrollDirection: Axis.horizontal,
          itemCount: 10,
          itemBuilder: (context, index) => BubbleStorie("name $index"),
        ),
      ),
    );
  }
}
