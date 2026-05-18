# 徳島大学漫画部エアコン

漫画部部室のエアコン電源状態を、スマートフォンやWebブラウザからリアルタイムで確認できるシステム。

## Overview
部室のエアコン消し忘れ問題を解決するために開発したIoTベースの監視システム。

クランプ型電流センサを利用してエアコンの消費電流を測定し、ESP32を通じてFirebase Realtime Databaseへ送信することで、遠隔からエアコンのON/OFF状態を確認できる。

## Motivation
2025年の夏、誰かが部室のエアコンを消し忘れたまま帰宅してしまい、翌日には部室が水浸しになっていた。

この出来事をきっかけに、遠隔からエアコンの稼働状態を確認できるシステムを開発した。

## Main Features
- エアコン電源状態のリアルタイム監視
- Webブラウザ対応
- Firebase Realtime Database連携
- ESP32によるWi-Fi通信
- 電流値によるON/OFF自動判定
- スマートフォン対応UI

## Tech Stack
- ESP32
- Arduino
- Firebase Realtime Database
- Flutter
- HTML / JavaScript
- Wi-Fi
- SCT-013 Current Sensor

## Web Application

[Open Web App](https://aircon-cc3d0.web.app/)


## Image
<img width="540" height="1170" alt="Screenshot_20260519_013549" src="https://github.com/user-attachments/assets/f0af3e44-b8ce-469d-ae6f-b583a0861e79" />

<img width="2040" height="1536" alt="260511124420425" src="https://github.com/user-attachments/assets/95be0922-effb-4fee-8e1a-af419c571c82" />




## System Architecture
```text
SCT-013 Sensor
      ↓
ESP32
      ↓ Wi-Fi
Firebase Realtime Database
      ↓
Web / Mobile App
