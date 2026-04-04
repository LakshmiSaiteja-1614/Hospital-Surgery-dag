# 🏥 Hospital Surgery Scheduling System (DAG-Based)

## 📌 Project Title

Hospital Surgery Scheduling Using Directed Acyclic Graph (DAG)

---

## 👥 Team Members

* Member 1: [Your Name]
* Member 2: [Teammate Name]

---

## ❗ Problem Statement

Efficient scheduling of surgeries in a hospital is important to avoid conflicts, delays, and improper use of operation theatres.
Some surgeries depend on the completion of others, which makes scheduling complex.

This project solves the problem using a **Directed Acyclic Graph (DAG)** to ensure proper order and dependency management.

---

## 🧠 Data Structure Used

* **Linked List** → to store surgery records dynamically
* **Graph (Adjacency Matrix)** → to represent dependencies between surgeries
* **Stack + DFS** → to perform topological sorting for scheduling

---

## ⚙️ Algorithm Explanation

1. **Create (Add Surgery)** → Insert a new node into the linked list

2. **Read (Display)** → Traverse and display all surgeries

3. **Update** → Modify existing surgery details

4. **Delete** → Remove a surgery node

5. **Dependency Handling (DAG)**

   * Surgeries are represented as nodes
   * Dependencies are represented as directed edges

6. **Topological Sorting (Scheduling)**

   * Use Depth First Search (DFS)
   * Push nodes into a stack after visiting
   * Pop stack to get valid surgery execution order

---

## 💻 Compilation Instructions

```bash
gcc main.c -o project
./project
```

---

## 🧾 Sample Output
<img width="354" height="205" alt="image" src="https://github.com/user-attachments/assets/4c968e8d-4362-4cf3-8946-f2a69c2e4f2a" />



---

## 🎥 Demo Video Link

