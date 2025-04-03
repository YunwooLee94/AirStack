# AirStack: Democratizing Intelligent Mobile Robotics

<div align="center">
  <img src="docs/assets/logo_horizontal_color.png" alt="AirStack Logo" width="400"/>
</div>

April 03 2025

AirStack is a comprehensive, modular autonomy stack for embodied AI and robotics developed by the [AirLab](https://theairlab.org) at Carnegie Mellon University's Robotics Institute. It provides a complete framework for developing, testing, and deploying autonomous mobile systems in both simulated and real-world environments.

[![GitHub](https://img.shields.io/github/license/castacks/AirStack)](https://github.com/castacks/AirStack/blob/main/LICENSE)
[![Documentation](https://img.shields.io/badge/docs-mkdocs-blue)](https://docs.theairlab.org/docs/)

## 🚀 Features

- **Modular Architecture**: Easily swap out components to customize for your specific needs
- **ROS 2 Integration**: Built on ROS 2 for robust inter-process communication
- **Simulation Support**: Integrated with NVIDIA Isaac Sim for high-fidelity simulation
- **Multi-Robot Capability**: Control and coordinate multiple robots simultaneously
- **Ground Control Station**: Monitor and control robots through an intuitive interface
- **Comprehensive Autonomy Stack**:
  - Robot Interface Layer
  - Sensor Integration
  - Perception Systems
  - Local Planning & Control
  - Global Planning
  - Behavior Management

## 📋 System Requirements

- **Docker**: With NVIDIA Container Toolkit support
- **NVIDIA GPU**: RTX 3070 or better (for local Isaac Sim)
- **Storage**: At least 25GB free space for Docker images
- **OS**: Ubuntu 22.04 recommended

## 🔧 Quick Start

### 1. Clone the Repository

```bash
git clone --recursive -j8 git@github.com:castacks/AirStack.git
cd AirStack
```

### 2. Install Docker with NVIDIA Support

Follow [NVIDIA's instructions](https://docs.nvidia.com/ai-enterprise/deployment/vmware/latest/docker.html) for installing Docker with NVIDIA GPU support. Make sure `docker-compose-plugin` is also installed.

### 3. Configure the Repository

```bash
./configure.sh
```

Follow the prompts to complete the initial configuration.

### 4. Get the Docker Images

#### Option 1: Pull from AirLab Registry (Preferred)

```bash
docker login airlab-storage.andrew.cmu.edu:5001
# Enter your andrew id (without @andrew.cmu.edu)
# Enter your andrew password

# Pull the images in the docker compose file
docker compose pull
```

#### Option 2: Build Docker Images From Scratch

```bash
# Download the Ascent Spirit SITL software package
bash simulation/isaac-sim/installation/download_sitl.bash

# Build the images locally (requires NVIDIA NGC access)
docker compose build
```

### 5. Launch the System

```bash
xhost +  # allow docker access to X-Server

# Start docker compose services
docker compose up -d
# For multiple robots: docker compose up -d --scale robot=3
```

This will automatically launch and play the Isaac Sim scene specified in the `.env` file.

### 6. Control the Robot

Find the RQT GUI window:
1. Click "Arm and Takeoff"
2. Click "Global Plan" in the trajectory window

You can also switch to "Fixed Trajectory" mode and click "Publish" to follow a predefined trajectory.

### 7. Shutdown

```bash
docker compose down
```

## 🏗️ System Architecture

AirStack follows a layered architecture approach:

```
Robot
├── Interface Layer: Communication with robot controllers
├── Sensors Layer: Data acquisition from various sensors
├── Perception Layer: State estimation and environment understanding
├── Local Layer: 
│   ├── World Model: Local environment representation
│   ├── Planning: Trajectory generation and obstacle avoidance
│   └── Controls: Trajectory following
├── Global Layer:
│   ├── World Model: Global environment mapping
│   └── Planning: Mission-level path planning
└── Behavior Layer: High-level decision making
```

## 📁 Repository Structure

- `robot/`: Contains the ROS 2 workspace for the robot autonomy stack
- `ground_control_station/`: Software for monitoring and controlling robots
- `simulation/`: Integration with Isaac Sim and simulation environments
- `docs/`: Comprehensive documentation
- `common/`: Shared libraries and utilities
- `tests/`: Testing infrastructure

## 🧪 Development

AirStack is designed with modularity in mind, making it straightforward to extend or replace components. The development workflow is centered around Docker containers for consistent environments.

For detailed development guidelines, see the [Developer Guide](https://docs.theairlab.org/docs/development/).

## 📚 Documentation

Comprehensive documentation is available at [https://docs.theairlab.org/docs/](https://docs.theairlab.org/docs/)

The documentation covers:
- Getting started guides
- Development workflows
- Component descriptions
- API references
- Simulation setup
- Real-world deployment

## 🤝 Contributing

We welcome contributions to AirStack! Please see our [Contributing Guidelines](https://docs.theairlab.org/docs/development/contributing/) for more information.

## 📄 License

AirStack is licensed under the Apache 2.0 or MIT license (to be finalized).


## 📧 Contact

For questions or support, please contact the AirLab team at [theairlab.org](https://theairlab.org).
