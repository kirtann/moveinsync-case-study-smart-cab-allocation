# Smart Cab Allocation System

Smart Cab Allocation System is a C++ program designed to manage and allocate cabs efficiently. This system provides functionality for both administrators and users to interact with the cab allocation services.

## Functionality

### Authentication

- **Admin Login**: The system allows administrators to log in with a username and password to access administrative functionalities.
- **User Login/Register**: Users can either log in with existing credentials or register as new users to access the cab allocation services.

### Administrator Functionalities

- **Add Cab**: Administrators can add new cabs to the system by providing the cab ID and location coordinates.
- **View All Cabs Details**: Administrators can view details of all cabs currently registered in the system, including their IDs and live locations.
- **Check Cab Location**: Administrators can check the current location of a specific cab by entering its ID.

### User Functionalities

- **Start a Trip**: Users can initiate a trip, although this functionality is incomplete in the current version of the system.
- **Get Nearest Cab**: Users have the option to find the nearest available cab from a given location, although this feature is not fully implemented.

## Object-Oriented Programming Concepts Utilised

The Smart Cab Allocation System utilizes several Object-Oriented Programming (OOP) concepts to structure and implement its functionalities:

1. **Encapsulation**:

   - The classes `Cab`, `Admin`, `User`, `UserManager`, and `Auth` encapsulate related data (attributes) and behaviors (methods) into coherent objects. For example, `Cab` encapsulates cab ID, location, and availability status, while `Admin` encapsulates administrator credentials and cab management functions.

2. **Abstraction**:

   - Each class in the system represents real-world entities (e.g., cabs, users, administrators) and abstracts away unnecessary details. For instance, the `Cab` class abstracts the concept of a cab, providing methods to interact with its properties without exposing its internal implementation.

3. **Inheritance**:

   - Inheritance is not explicitly demonstrated in the provided code. However, in a more extensive system, one could envision a hierarchy of classes where more specialized classes inherit properties and behaviors from a more generalized class.

4. **Composition**:
   - Composition is utilized in the relationship between the `Admin` class and the `Cab` class. An `Admin` object contains a vector of `Cab` objects, representing the composition of an admin with multiple cabs under their management.

## Space and Time Complexity Analysis

### Space Complexity

- The space complexity of the Smart Cab Allocation System primarily depends on the number of cabs and users registered in the system, as well as the size of data structures used for storage.
- The space complexity of the provided code is primarily determined by the following factors:
  - The number of `Cab` objects stored in the `Admin` class vector.
  - The number of user credentials stored in the `UserManager` class hashmap.

### Time Complexity

- The time complexity of the Smart Cab Allocation System varies depending on the operations performed, such as adding a cab, authenticating a user, or retrieving cab details.
- In the provided code, time complexity is influenced by operations such as:
  - Searching for a specific cab or user in the system.
  - Adding a new cab to the system.
  - Authenticating a user during login.
- The time complexity can be analyzed based on the algorithms used for these operations. For example, searching in a vector has a time complexity of O(n), while hashing and searching in a hashmap have an average time complexity of O(1).
- Further optimization can be achieved by employing more efficient algorithms or data structures for critical operations, such as using binary search for sorted data or optimizing hash functions for hashmap operations.

## Future Scopes for Improvement

### Space Complexity Optimization

- Implement more efficient data structures for storage, such as balanced binary search trees or hashmaps with better collision resolution strategies.
- Utilize database systems for persistent storage, which can optimize space usage and provide scalability.

### Time Complexity Optimization

- Employ advanced algorithms and data structures for critical operations, such as searching and retrieval.
- Implement caching mechanisms to reduce the need for repetitive data retrieval and improve overall system performance.
- Parallelize and optimize critical processes to leverage multi-core architectures and improve throughput.

### Overall System Enhancements

- Introduce load balancing and scaling mechanisms to handle increased user and cab registrations efficiently.
- Add the data into the database for scalability of the system and so that data exists not just for each run.

### System Flow

- The system prompts users with a choice between admin login, user login/register, or exit.
- Upon successful authentication, users are directed to their respective functionalities.
- Administrators can perform tasks related to cab management, while users can utilize cab allocation services.

## Usage

1. **Admin Login**: Administrators should choose the "Admin login" option and provide their credentials when prompted.
2. **User Login/Register**: Users can select the appropriate option to either log in with existing credentials or register as new users.
3. **Admin Functionalities**: After successful authentication, administrators can add cabs, view all cab details, and check cab locations.
4. **User Functionalities**: Authenticated users can start a trip or find the nearest cab, although these features are currently incomplete.

## Dependencies

- This system utilizes standard C++ libraries such as `iostream`, `unordered_map`, `cmath`, and `vector`.

## Future Improvements

- Implement the remaining functionalities for users, including starting a trip and finding the nearest cab.
- Enhance error handling and input validation to improve system robustness.
