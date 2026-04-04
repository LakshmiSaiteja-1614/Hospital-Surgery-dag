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
**🧾 Sample Run 1 – Adding Surgeries**

<img width="354" height="205" alt="image" src="https://github.com/user-attachments/assets/34f1d5ba-2b6b-465d-929d-6663646840ff" /> 

<img width="328" height="106" alt="Screenshot 2026-04-04 at 8 56 12 PM" src="https://github.com/user-attachments/assets/46988850-4bf3-419c-9bc1-6354b2d3218e" />

<img width="328" height="106" alt="Screenshot 2026-04-04 at 8 56 12 PM" src="https://github.com/user-attachments/assets/2ec78b5a-a75d-412c-9e23-e65f7d8f27cb" />

<img width="328" height="106" alt="Screenshot 2026-04-04 at 8 56 12 PM" src="https://github.com/user-attachments/assets/d9f0704d-eb66-47ac-af20-c9fbda1c33ee" />


**🧾 Sample Run 2 – Display Surgeries**

<img width="460" height="116" alt="Screenshot 2026-04-04 at 9 01 05 PM" src="https://github.com/user-attachments/assets/0ce816ee-2619-4807-b9e8-ea4da9c83116" />

  
**🧾 Sample Run 3 – Add Dependencies (DAG)**

<img width="306" height="86" alt="Screenshot 2026-04-04 at 9 03 21 PM" src="https://github.com/user-attachments/assets/18b989d8-9954-47fe-8b5f-1baf01577470" />

<img width="337" height="81" alt="Screenshot 2026-04-04 at 9 05 00 PM" src="https://github.com/user-attachments/assets/d5894e0b-c9bd-4b16-a3e6-f789c967a7a9" />


**🧾 Sample Run 4 – Display Graph (Adjacency Matrix)**

<img width="257" height="119" alt="Screenshot 2026-04-04 at 9 06 38 PM" src="https://github.com/user-attachments/assets/3ce561fa-fe56-47bf-aff4-9b0385ebfa22" />


**🧾 Sample Run 5 – Topological Sort (Schedule)**

<img width="297" height="81" alt="Screenshot 2026-04-04 at 9 08 39 PM" src="https://github.com/user-attachments/assets/72939cb1-8cf9-4ff2-936f-e5f2c4d1d9af" />


**🧾 Sample Run 6 – Search Surgery**

<img width="307" height="59" alt="Screenshot 2026-04-04 at 9 10 04 PM" src="https://github.com/user-attachments/assets/b2dd579b-48b0-4553-b71a-e25a51a838ff" />


**🧾 Sample Run 7 – Update Surgery**

<img width="318" height="91" alt="Screenshot 2026-04-04 at 9 11 30 PM" src="https://github.com/user-attachments/assets/133c5aca-e8d9-4a63-b8c4-e7a4170543f0" />


**🧾 Sample Run 8 – Delete Surgery**

<img width="343" height="64" alt="Screenshot 2026-04-04 at 9 12 26 PM" src="https://github.com/user-attachments/assets/754f4c31-ba49-4829-8ecc-d5b6064c74ab" />

  
**🧾 Sample Run 9 – Exit**

<img width="333" height="208" alt="Screenshot 2026-04-04 at 9 12 41 PM" src="https://github.com/user-attachments/assets/67fa032b-3251-411d-90e1-4c00e777ea9c" />

  
---

## 🎥 Demo Video Link

