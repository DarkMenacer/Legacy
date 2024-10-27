// If a class doesn't deal with memory internally, it doesn't require an explicit destructor definition
//
// If a class deals with memory however, then destructor is required to deallocate the memory, but along with destructor 2 more functions are required
// 2. Copy constructor
// 3. Copy assignment operator
//
// If a class also happens to deal with transferring ownership of the memory it allocated, then following 2 functions needs to explicitly declared as well
// 4. Move constructor
// 5. Move assignment operator
//
// Refer: https://www.youtube.com/watch?v=yMX7ky3pyIA&ab_channel=Code%2CTech%2CandTutorials and https://www.youtube.com/watch?v=OJ7z996wpVk&ab_channel=Code%2CTech%2CandTutorials
