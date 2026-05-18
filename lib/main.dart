import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'firebase_options.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();

  await Firebase.initializeApp(
    options: DefaultFirebaseOptions.currentPlatform,
  );

  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Aircon Monitor',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const AirconPage(),
    );
  }
}

class AirconPage extends StatefulWidget {
  const AirconPage({super.key});

  @override
  State<AirconPage> createState() => _AirconPageState();
}

class _AirconPageState extends State<AirconPage> {
  // 나중에 Firebase 값으로 바뀔 변수
  bool isOn = false;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Aircon Status"),
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
      ),

      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [

            // 상태 아이콘
            Icon(
              isOn ? Icons.ac_unit : Icons.power_off,
              size: 100,
              color: isOn ? Colors.green : Colors.red,
            ),

            const SizedBox(height: 20),

            // 상태 텍스트
            Text(
              isOn ? "🟢 에어컨 ON" : "🔴 에어컨 OFF",
              style: const TextStyle(fontSize: 28),
            ),

            const SizedBox(height: 40),

            // 테스트용 버튼 (나중에 Firebase로 대체)
            ElevatedButton(
              onPressed: () {
                setState(() {
                  isOn = !isOn;
                });
              },
              child: const Text("테스트 토글"),
            ),
          ],
        ),
      ),
    );
  }
}