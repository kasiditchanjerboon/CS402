# CS402 Project Parking simulation system
# Name Group 62wil48

## Setup software
* Eclipse IDE for UI
* Arduino IDE for board arduino uno r3

## Setup Eclipse
### step 1
- download Java JDK this link : https://www.oracle.com/java/technologies/javase-jdk14-downloads.html
### step 2
- download Eclipse IDE 2020‑03 this link : https://www.eclipse.org/downloads/
### step 3
- install software

## Setup Arduino IDE
### step 1
- download Arduino IDE this link : https://www.arduino.cc/en/main/software
### step 2
- install software
### step 3
- download Library sensor
- open Arduino IDE --> Sketch --> Include Library --> Manage Libraries --> search "NewPing" --> install
- open Arduino IDE --> File --> Examples --> 06.sensors--> ping
### step 4
- download Library ReadWrite SD card
- open Arduino IDE --> Sketch --> Include Library --> Manage Libraries --> search "SD" --> install
- open Arduino IDE --> File --> Examples --> SD--> ReadWrite


## Code for UI in Eclipse IDE
- create new java project
- create new class on project
- copy file "src" this link : https://github.com/kasiditchanjerboon/CS402.git

## Code for UI in Arduino IDE
- copy file "testfinal" this link : https://github.com/kasiditchanjerboon/CS402.git

## Directory Tree
```bash
Folder PATH listing for volume DATA
Volume serial number is CE20-E409
D:.
├───.metadata
│   ├───.mylyn
│   │   ├───.taskListIndex
│   │   └───contexts
│   └───.plugins
│       ├───org.eclipse.buildship.core
│       ├───org.eclipse.core.resources
│       │   ├───.history
│       │   │   ├───1
│       │   │   ├───10
│       │   │   ├───11
│       │   │   ├───12
│       │   │   ├───13
│       │   │   ├───15
│       │   │   ├───16
│       │   │   ├───17
│       │   │   ├───18
│       │   │   ├───19
│       │   │   ├───1a
│       │   │   ├───1b
│       │   │   ├───1d
│       │   │   ├───1e
│       │   │   ├───1f
│       │   │   ├───2
│       │   │   ├───20
│       │   │   ├───21
│       │   │   ├───22
│       │   │   ├───23
│       │   │   ├───24
│       │   │   ├───25
│       │   │   ├───26
│       │   │   ├───27
│       │   │   ├───28
│       │   │   ├───29
│       │   │   ├───2a
│       │   │   ├───2b
│       │   │   ├───2c
│       │   │   ├───2d
│       │   │   ├───2e
│       │   │   ├───3
│       │   │   ├───31
│       │   │   ├───32
│       │   │   ├───33
│       │   │   ├───34
│       │   │   ├───35
│       │   │   ├───36
│       │   │   ├───37
│       │   │   ├───38
│       │   │   ├───39
│       │   │   ├───3a
│       │   │   ├───3b
│       │   │   ├───3e
│       │   │   ├───3f
│       │   │   ├───4
│       │   │   ├───40
│       │   │   ├───41
│       │   │   ├───42
│       │   │   ├───43
│       │   │   ├───44
│       │   │   ├───45
│       │   │   ├───46
│       │   │   ├───48
│       │   │   ├───49
│       │   │   ├───4a
│       │   │   ├───4c
│       │   │   ├───4d
│       │   │   ├───4e
│       │   │   ├───5
│       │   │   ├───50
│       │   │   ├───51
│       │   │   ├───52
│       │   │   ├───53
│       │   │   ├───54
│       │   │   ├───55
│       │   │   ├───56
│       │   │   ├───57
│       │   │   ├───58
│       │   │   ├───59
│       │   │   ├───5a
│       │   │   ├───5b
│       │   │   ├───5c
│       │   │   ├───5d
│       │   │   ├───5e
│       │   │   ├───5f
│       │   │   ├───6
│       │   │   ├───60
│       │   │   ├───61
│       │   │   ├───62
│       │   │   ├───64
│       │   │   ├───65
│       │   │   ├───66
│       │   │   ├───67
│       │   │   ├───68
│       │   │   ├───69
│       │   │   ├───6b
│       │   │   ├───6c
│       │   │   ├───6d
│       │   │   ├───6e
│       │   │   ├───6f
│       │   │   ├───7
│       │   │   ├───70
│       │   │   ├───72
│       │   │   ├───73
│       │   │   ├───74
│       │   │   ├───75
│       │   │   ├───77
│       │   │   ├───78
│       │   │   ├───79
│       │   │   ├───7a
│       │   │   ├───7b
│       │   │   ├───7c
│       │   │   ├───7d
│       │   │   ├───7e
│       │   │   ├───7f
│       │   │   ├───8
│       │   │   ├───80
│       │   │   ├───81
│       │   │   ├───83
│       │   │   ├───84
│       │   │   ├───86
│       │   │   ├───87
│       │   │   ├───88
│       │   │   ├───8a
│       │   │   ├───8b
│       │   │   ├───8c
│       │   │   ├───8d
│       │   │   ├───8e
│       │   │   ├───9
│       │   │   ├───92
│       │   │   ├───93
│       │   │   ├───94
│       │   │   ├───95
│       │   │   ├───96
│       │   │   ├───97
│       │   │   ├───98
│       │   │   ├───9b
│       │   │   ├───9d
│       │   │   ├───9e
│       │   │   ├───9f
│       │   │   ├───a
│       │   │   ├───a0
│       │   │   ├───a1
│       │   │   ├───a2
│       │   │   ├───a3
│       │   │   ├───a4
│       │   │   ├───a5
│       │   │   ├───a6
│       │   │   ├───a7
│       │   │   ├───a8
│       │   │   ├───a9
│       │   │   ├───aa
│       │   │   ├───ab
│       │   │   ├───ac
│       │   │   ├───af
│       │   │   ├───b
│       │   │   ├───b0
│       │   │   ├───b1
│       │   │   ├───b2
│       │   │   ├───b3
│       │   │   ├───b4
│       │   │   ├───b5
│       │   │   ├───b6
│       │   │   ├───b7
│       │   │   ├───b8
│       │   │   ├───b9
│       │   │   ├───bb
│       │   │   ├───bd
│       │   │   ├───be
│       │   │   ├───bf
│       │   │   ├───c
│       │   │   ├───c0
│       │   │   ├───c2
│       │   │   ├───c3
│       │   │   ├───c4
│       │   │   ├───c5
│       │   │   ├───c6
│       │   │   ├───c7
│       │   │   ├───c8
│       │   │   ├───c9
│       │   │   ├───ca
│       │   │   ├───cb
│       │   │   ├───cc
│       │   │   ├───cf
│       │   │   ├───d
│       │   │   ├───d0
│       │   │   ├───d2
│       │   │   ├───d3
│       │   │   ├───d4
│       │   │   ├───d5
│       │   │   ├───d6
│       │   │   ├───d8
│       │   │   ├───da
│       │   │   ├───db
│       │   │   ├───dc
│       │   │   ├───dd
│       │   │   ├───de
│       │   │   ├───df
│       │   │   ├───e
│       │   │   ├───e1
│       │   │   ├───e2
│       │   │   ├───e3
│       │   │   ├───e4
│       │   │   ├───e6
│       │   │   ├───e8
│       │   │   ├───e9
│       │   │   ├───ea
│       │   │   ├───eb
│       │   │   ├───ef
│       │   │   ├───f0
│       │   │   ├───f1
│       │   │   ├───f2
│       │   │   ├───f3
│       │   │   ├───f4
│       │   │   ├───f5
│       │   │   ├───f6
│       │   │   ├───f7
│       │   │   ├───f8
│       │   │   ├───fa
│       │   │   ├───fb
│       │   │   ├───fc
│       │   │   ├───fd
│       │   │   ├───fe
│       │   │   └───ff
│       │   ├───.projects
│       │   │   ├───300
│       │   │   │   ├───org.eclipse.jdt.apt.core
│       │   │   │   └───org.eclipse.jdt.core
│       │   │   └───UI
│       │   │       ├───org.eclipse.jdt.apt.core
│       │   │       └───org.eclipse.jdt.core
│       │   ├───.root
│       │   │   └───.indexes
│       │   └───.safetable
│       ├───org.eclipse.core.runtime
│       │   └───.settings
│       ├───org.eclipse.debug.core
│       │   └───.launches
│       ├───org.eclipse.debug.ui
│       ├───org.eclipse.e4.workbench
│       ├───org.eclipse.eclemma.core
│       │   └───.execdata
│       ├───org.eclipse.emf.common.ui
│       ├───org.eclipse.epp.logging.aeri.ide
│       │   └───org.eclipse.epp.logging.aeri.ide.server
│       │       ├───http-cache.lucene60
│       │       └───local-history.lucene60
│       ├───org.eclipse.jdt.core
│       ├───org.eclipse.jdt.launching
│       ├───org.eclipse.jdt.ui
│       ├───org.eclipse.ltk.core.refactoring
│       │   └───.refactorings
│       │       ├───300
│       │       │   └───2561
│       │       │       └───11
│       │       │           └───46
│       │       └───UI
│       │           └───2563
│       │               └───5
│       │                   └───20
│       ├───org.eclipse.ltk.ui.refactoring
│       ├───org.eclipse.m2e.logback.configuration
│       ├───org.eclipse.mylyn.bugzilla.core
│       ├───org.eclipse.mylyn.commons.notifications.ui
│       ├───org.eclipse.mylyn.context.core
│       │   └───contexts
│       ├───org.eclipse.mylyn.tasks.ui
│       ├───org.eclipse.oomph.setup
│       ├───org.eclipse.oomph.setup.ui
│       ├───org.eclipse.recommenders.news.impl
│       │   └───downloads
│       ├───org.eclipse.team.ui
│       ├───org.eclipse.tips.ide
│       ├───org.eclipse.ui.ide
│       ├───org.eclipse.ui.intro
│       ├───org.eclipse.ui.workbench
│       ├───org.eclipse.ui.workbench.texteditor
│       └───org.eclipse.userstorage.oauth
├───.recommenders
│   ├───caches
│   └───index
│       └───http___download_eclipse_org_recommenders_models_photon_
├───300
│   ├───.settings
│   ├───bin
│   └───src
└───UI
    ├───.settings
    ├───bin
    └───src
    ```
