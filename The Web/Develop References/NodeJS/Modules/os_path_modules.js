const os_v = require('os')
const path_v = require('path')

//os functions
console.log(`The user of this system is ${os_v.userInfo()} and the system has been running for ${os_v.uptime()}\n`)
const currentOS = {
    name: os_v.type(),
    release: os_v.release(),
    totalMem: os_v.totalmem(),
    freeMem: os_v.freemem(),
  }
console.log(currentOS)

//path functions
const filePath = path_v.join('/fake_parent/', 'child_folder', 'test.txt')
console.log(filePath)
const absolute = path_v.resolve(__dirname, 'fake_parent', 'child_folder', 'test.txt')
console.log(absolute)