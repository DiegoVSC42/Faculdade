import 'package:flutter/material.dart';
import 'package:flutter_svg_provider/flutter_svg_provider.dart';

class BubbleStorie extends StatelessWidget {
  const BubbleStorie(this.text, {super.key});

  final String text;

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Container(
          width: 80,
          height: 80,
          decoration: BoxDecoration(
            shape: BoxShape.circle,
            color: Colors.grey[400],
            image: const DecorationImage(
                image: Svg('lib/assets/images/user_placeholder.svg')),
          ),
        ),
        Text(text)
      ],
    );
  }
}
