# 🏥 Hospital Waiting List System

A priority queue-based hospital patient management system implemented in C using a linked list. Patients are served based on priority level — emergency cases are handled before general ones.

## 📋 Overview

Built as a Data Structures lab project under Prof. Swapnil S. Sonawane at VIT Mumbai. The system simulates a real hospital triage queue where patients are inserted by priority and dequeued in order.

## 🛠️ Tech Stack

- **Language:** C
- **Data Structure:** Priority Queue using Singly Linked List
- **Concepts:** Dynamic memory allocation, pointer-based insertion/deletion

## ⚙️ How It Works

- Each patient node stores: `name`, `age`, `priority level`, and `next` pointer
- **Insert:** Patients are inserted in sorted order by priority (lower number = higher priority)
- **Serve (Dequeue):** Always removes the highest-priority patient from the front
- **Display:** Shows the full queue in priority order

## 🧪 Priority Levels

| Priority | Category |
|---|---|
| 1 | Emergency / Critical |
| 2 | Urgent |
| 3 | General |

## 🚀 Compile & Run

```bash
gcc hospital_queue.c -o hospital
./hospital
```

## 📁 Files

- `hospital_queue.c` — Main source file with queue logic and menu-driven interface

## 👨‍💻 Author

Punit Saini — VIT Mumbai, Computer Engineering
Subject: Data Structures in C (Prof. Sonawane)
