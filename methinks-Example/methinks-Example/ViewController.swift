//
//  ViewController.swift
//  methinks-Example
//
//  Created by Philip Yun on 7/23/20.
//  Copyright © 2020 methinks. All rights reserved.
//

import UIKit
import methinksiOS
class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        MTKSDK.shared().logEvent("fist view")
        MTKSDK.shared().setCustomTrackingViewTitle("First View")
        let label = UILabel()
        label.text = "Hello World!"
        self.view.backgroundColor = UIColor.systemBackground
        self.view.addSubview(label)
        label .sizeToFit()
        label.center = self.view.center
        
        
        
        // Do any additional setup after loading the view.
    }


}

