# Raspberry Pi integration

The Raspberry Pi is intended to coordinate smart-home modules. The transport and application protocol have not yet been finalized.

Before implementation, decide:
- Wi-Fi, Ethernet, MQTT, HTTP, ESP-NOW, or another transport
- Device naming and discovery
- Message schema and retained state
- Availability/heartbeat behaviour
- Firmware update strategy
- Authentication and credential storage

Do not commit Wi-Fi passwords, broker credentials, API tokens, or private network details. Keep this folder as integration documentation until the protocol is selected.
