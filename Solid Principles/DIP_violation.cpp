// Dependency Inversion principle

// there should be interface between high level module and low level module

// user service has 2 references saveToSQL and saveToMongoDB
// if we need to remove saveToSQL and introduce saveToCassanedra we need to modify and user service

// breaking OCP