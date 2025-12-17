import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

void main() => runApp(MaterialApp(home: DetectorApp()));

class DetectorApp extends StatefulWidget {
  @override
  _DetectorAppState createState() => _DetectorAppState();
}

class _DetectorAppState extends State<DetectorApp> {
  static const _eventChannel = EventChannel('com.example.native_camera/detection');
  bool _detected = false;

  @override
  void initState() {
    super.initState();
    _eventChannel.receiveBroadcastStream().listen((res) {
      setState(() => _detected = res);
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Text(_detected ? "ЛИНИЯ НАЙДЕНА" : "ПОИСК...", 
          style: TextStyle(fontSize: 30, color: _detected ? Colors.green : Colors.red)),
      ),
    );
  }
}