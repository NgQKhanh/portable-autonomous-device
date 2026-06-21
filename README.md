# Portable Autonomous Device (PAD)

> A robust, C++ 17 based modular application designed for portable autonomous systems.

# 1. Overview
The **Portable Autonomous Device (PAD)** is a software framework and application designed to manage and control autonomous hardware units. The architecture that explores how to build a reusable, portable, and testable control framework for autonomous smart appliances (e.g: AGVs, robotic vacuum cleaners, and line-following robots,...)

The framework enables a single control logic implementation to operate on multiple platformsplatforms: Windows (Simulation), Linux Embedded, RTOS-based MCU. By separating application logic from hardware and platform dependencies, the framework promotes code reuse, maintainability, and platform independence.

# 2. Architecture

The system is designed with a layered architecture:

### 2.1 Application Layer
This is the top-level executable layer. The Application layer is responsible for implementing application-specific behavior and business logic.

### 2.2 Framework Layer
This layer provides the reusable foundation and control architecture for autonomous smart appliance applications. It contains the following internal modules:
* **Domain Module:** "brain" of the system, containing the core control logic that drives the system's behavior.
* **Platform Module:** Provides OS-level abstractions and system runtime services.
* **Adapters Module:** Integrations with hardware, simulations, and external systems.
* **Infrastructure Module:** Provides common technical services such as logging, configuration, diagnostics, and utilities.

# 3. Directory Structure

```text

pad_src/
├── Application/
├── Framework/
│   ├── Domain/
│   ├── Platform/
│   ├── Adapters/
│   └── Infrastructure/
├── Tests/
└── ThirdParty/

```

# 4. Build and Run

To build and run this project, ensure you have the following installed on your system:

| Tool | Minimum Version | Purpose |
| :--- | :--- | :--- |
| **C++ Compiler** | C++17 Support | Core compilation (GCC 8+, Clang 7+, or MSVC 19.14+) |
| **CMake** | 3.14+ | Build system generator (Requires FetchContent support) |
| **Git** | 2.0+ | Version control |
| **Clang-Format** | 10.0+ | Strict code formatting enforcement


Build Application (for Window: `win-app-config | win-app`):
```bash
cmake --preset win-app-config
cmake --build --preset win-app
```

Build Unit Tests:
```bash
cmake --preset win-test-config
cmake --build --preset win-test
```

Run:
```bash
./_build/app/Application/pad_app
```

---
*Software Version: 1.0.0 | Developed with Modern C++ Architecture Best Practices*